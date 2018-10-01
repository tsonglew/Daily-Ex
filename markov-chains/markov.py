import numpy as np
import random as rm

states = ['Sleep', 'Icecream', 'Run']
transition_names = [['SS', 'SI', 'SR'], ['IS', 'II', 'IR'], ['RS', 'RI', 'RR']]
transition_matix = [[0.2,0.6,0.2],[0.1,0.6,0.3],[0.2,0.7,0.1]]

if sum([sum(transition_matix[0]), sum(transition_matix[1]), sum(transition_matix[2])]) != 3:
    print('transition matrix wrong')
    exit(0)

def forecast(days):
    activity_today = 'Sleep'
    activity_list = [activity_today]
    print(f'today\'s activity: {activity_today}')

    i = 0
    prob = 1
    while i != days:
        i += 1
        if activity_today == 'Sleep':
            change = np.random.choice(transition_names[0], replace=True, p=transition_matix[0])
            if change == 'SS':
                prob *= 0.2
                activity_list.append('Sleep')
            elif change == 'SI':
                prob *= 0.6
                activity_list.append('Icecream')
                activity_today = 'Icecream'
            elif change == 'SR':
                prob *= 0.2
                activity_list.append('Run')
                activity_today = 'Run'
        elif activity_today == 'Icecream':
            change = np.random.choice(transition_names[1], replace=True, p=transition_matix[1])
            if change == 'IS':
                prob *= 0.1
                activity_list.append('Sleep')
                activity_today = 'Sleep'
            elif change == 'II':
                prob *= 0.6
                activity_list.append('Icecream')
            elif change == 'IR':
                prob *= 0.3
                activity_list.append('Run')
                activity_today = 'Run'
        elif activity_today == 'Run':
            change = np.random.choice(transition_names[2], replace=True, p=transition_matix[2])
            if change == 'RS':
                prob *= 0.2
                activity_list.append('Sleep')
                activity_today = 'Sleep'
            elif change == 'RI':
                prob *= 0.7
                activity_list.append('Icecream')
                activity_today = 'Icecream'
            elif change == 'RR':
                prob *= 0.1
                activity_list.append('Run')
    print(f'Possible states: {str(activity_list)}')
    print(f'End state after {str(days)} days: {activity_today}')
    print(f'Probabiliy of the possible sequence of states: {str(prob)}')

forecast(2)