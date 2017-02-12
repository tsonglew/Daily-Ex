#-*- coding: utf-8 -*-
from flask import Flask
from mongokit import Connection, Document

# configuration
MONGODB_HOST = '121.42.12.214'
MONGODB_PORT = 27017

# create the little application object
app = Flask(__name__)
app.config.from_object(__name__)

# connect to the database
connection = Connection(app.config['MONGODB_HOST'],
                        app.config['MONGODB_PORT'])
class Week(Document):
    """
    :class: Week

    每周空闲教室存储
    """
    __collection__ = 'weeks'
    __database__ = 'weekdb'
    structure = {
            'bno': unicode,
            'weekNo': unicode,
            'mon': dict,
            'tue': dict,
            'wed': dict,
            'thu': dict,
            'fri': dict
    }

    def __repr__(self):
        return '<Mongo Week bno:{} weekNo:{}>'.format(self['bno'], self['weekNo'])

connection.register([Week])
