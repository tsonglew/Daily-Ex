#-*- coding: utf-8 -*-
from con import connection
import xlrd
import sys

table_path = './classroom_table.xls'
data = xlrd.open_workbook(table_path)
all_tables = data.sheets()

RESET_FLAG = 0


def list_minus(a, b):
    temp = []
    for a_each in a:
        if a_each not in b:
            temp.append(a_each)
    return temp


def update_each(table):
    """
    :function: update_each
    :args:
        - table: 课表

    根据每个年级的课表更新空闲教室表
    """


    def init_weekdays(weekday_list):
        """将每天对应的节次设定为空列表"""
        for sec in range(1, 15):
            weekday_list['%d' % sec] = list()

    def init_week(week_name, bno):
        """初始化每周每天对应的字典"""
        week = connection.Week()
        week['weekNo'] = week_name
        week['bno'] = bno
        week['mon'] = dict()
        week['tue'] = dict()
        week['wed'] = dict()
        week['thu'] = dict()
        week['fri'] = dict()
        init_weekdays(week['mon'])
        init_weekdays(week['tue'])
        init_weekdays(week['wed'])
        init_weekdays(week['thu'])
        init_weekdays(week['fri'])
        week.save()
        sys.stdout.write('weekNo:{w} bno:{b} initialiezed!\n'.format(w=week['weekNo'],b=week['bno']))

    def reset_week(week):
        """重置每周每天对应的字典"""
        init_weekdays(week['mon'])
        init_weekdays(week['tue'])
        init_weekdays(week['wed'])
        init_weekdays(week['thu'])
        init_weekdays(week['fri'])
        week.save()
        sys.stdout.write('{w} has been reseted!\n'.format(w=' '.join([week['bno'], week['weekNo']])))

    sys.stdout.write('Working on the table...\n')
    # 初始化上课教室
    for loc in [u'7', u'8']:
        for week_count in range(1, 21):
            week =  connection.Week.find_one({'weekNo': 'week%d'%week_count, 'bno': loc})
            if not week:
                init_week(u'week%d'%week_count, loc)
            else:
                if not RESET_FLAG: reset_week(week)
                else: sys.stdout.write("{w}/{l} already exits!\n".format(w=week['weekNo'], l=week['bno']))

    # 添加所有上课的教室
    rows_count = table.nrows
    for count in range(rows_count):
        values = table.row_values(count)
        times = values[:3]    # 上课时间 1-3
        val_locs = values[3:]    # 上课地点 1-3
        locations = list(str(int(each)) for each in val_locs if isinstance(each, float) and int(each/1000) in [7, 8])
        if not len(locations): continue
        for time in times:
            # 上课地点为空，跳至下一循环
            if not time: continue
            # 上课的星期
            weekday = time[time.index(u'\u671f')+1]
            # 上课的节次
            sec_li = list(int(i) for i in time[time.index(u'\u7b2c')+1:time.index(u'\u8282')].split('-'))
            secs = range(sec_li[0], sec_li[1]+1)
            # 上课的周次
            week_li = list(int(i) for i in time[time.index('{')+1:time.index(u'\u5468')].split('-'))
            # 单双周筛选
            if u'\u5355' in time:
                weeks = list(each for each in range(week_li[0], week_li[1]+1) if each%2!=0)
            if u'\u53cc' in time:
                weeks = list(each for each in range(week_li[0], week_li[1]+1) if each%2==0)
            else:
                weeks = list(each for each in range(week_li[0], week_li[1]+1))

            # 将教室添加到对应周对应星期对应的节次
            for do_week in weeks:
                if weekday == u'\u4e00':
                    ft_weekday = 'mon'
                elif weekday == u'\u4e8c':
                    ft_weekday = 'tue'
                elif weekday == u'\u4e09':
                    ft_weekday = 'wed'
                elif weekday == u'\u56db':
                    ft_weekday = 'thu'
                elif weekday == u'\u4e94':
                    ft_weekday = 'fri'
                for each_loc in locations:
                    bno = each_loc[0]
                    find_week = connection.Week.find_one({'weekNo': 'week%d'%do_week, 'bno': bno})
                    if not find_week: continue
                    weekdaydict = find_week[ft_weekday]

                    for each_sec in secs:
                        weekdaydict[str(each_sec)].append(each_loc)
                    find_week.save()
    sys.stdout.write('All from tables written!\n')


def change_to_free(bno, cm_all):
    """将上课教室表修改为空闲教室表"""
    sys.stdout.write("Working on {b}...\n".format(b=bno))
    weekday_list = ['mon', 'tue', 'wed', 'thu', 'fri']
    for week_count in range(1, 21):
        change_week = connection.Week.find_one({'weekNo':u'week%d'%week_count,'bno':bno})
        for weekday in weekday_list:
            for each_key in change_week[weekday].keys():
                change_week[weekday][each_key] = list_minus(cm_all, change_week[weekday][each_key])
        change_week.save()
    sys.stdout.write("bno: {b} handled!\n".format(b=bno))


if __name__ == '__main__':
    # 七号楼和八号楼所有的教室
    s_all = [u'7101',u'7102',u'7103',u'7104',u'7105',u'7106',u'7107',u'7108',u'7109',
             u'7201',u'7202',u'7203',u'7204',u'7205',u'7206',u'7207',u'7208',u'7209',u'7211',
             u'7301',u'7302',u'7303',u'7304',u'7305',u'7306',u'7307',u'7308',u'7309',u'7311',
             u'7401',u'7402',u'7403',u'7404',u'7405',u'7406',u'7407',u'7408',u'7409',u'7410',u'7411',
             u'7501',u'7503',u'7505']
    e_all = [u'8101',u'8102',u'8103',u'8104',u'8105',u'8106',u'8107',u'8108',u'8109',
             u'8110',u'8111',u'8112',u'8201',u'8202',u'8203',u'8204',u'8205',u'8206',
             u'8207',u'8208',u'8209',u'8210',u'8211',u'8212',u'8213',u'8214',u'8215',
             u'8216',u'8301',u'8302',u'8303',u'8304',u'8305',u'8306',u'8307',u'8308',
             u'8309',u'8310',u'8311',u'8312',u'8313',u'8314',u'8315',u'8316',u'8401',
             u'8402',u'8403',u'8404',u'8405',u'8406',u'8407',u'8408',u'8409',u'8410',
             u'8411',u'8412',u'8413',u'8414',u'8415',u'8416',u'8501',u'8502',u'8503',
             u'8504',u'8505',u'8506',u'8507',u'8508',u'8509',u'8510',u'8511',u'8512',
             u'8513',u'8514',u'8515',u'8516',u'8716',u'8717']
    for each_table in all_tables:
        update_each(each_table)
        RESET_FLAG = 1
    change_to_free(u'7', s_all)
    change_to_free(u'8', e_all)
