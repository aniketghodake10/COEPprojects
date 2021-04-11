import pandas as pd

def flsr(a):
    return float('{:.5f}'.format(float(a)))

data  = {'Days':['Weekday','Weekday','Weekday','Holiday','Saturday','Weekday','Holiday','Sunday','Weekday','Weekday',
                 'Saturday','Weekday','Weekday','Weekday','Weekday','Saturday','Weekday','Holiday','Weekday','Weekday'],
         'Season':['Spring','Winter','Winter','Winter','Summer','Autumn','Summer','Summer','Winter','Summer','Spring',
                   'Summer','Winter','Summer','Winter','Autumn','Autumn','Spring','Spring','Spring'],
         'Fog':['Nonee','Nonee','Nonee','High','Normal','Normal','High','Normal','High','Nonee','High','High','Normal',
                'High','Normal','High','Nonee','Normal','Normal','Normal'],
         'Rain':['None','Slight','None','Slight','None','None','Slight','None','Heavy','Slight','Heavy','Slight',
                 'None','None','Heavy','Slight','Heavy','Slight','None','Heavy'],
         'Class':['OnTime','OnTime','OnTime','Late','OnTime','VeryLate','OnTime','OnTime','VeryLate','OnTime',
                  'Cancelled','OnTime','Late','OnTime','VeryLate','OnTime','OnTime','OnTime','OnTime','OnTime']}

days = ['Weekday','Holiday','Saturday','Sunday']
season = ['Spring','Winter','Autumn','Summer']
fog = ['Nonee','High','Normal']
rain = ['None','Slight','Heavy']
attributes = [days,season,fog,rain]
df = pd.DataFrame(data)
# print(df)

dff_data = {'Features':[],'OnTime':[],'Late':[],'VeryLate':[],'Cancelled':[]}

columns = ['Days','Season','Fog','Rain']
ClassAttributes = ['OnTime','Late','VeryLate','Cancelled']

for i in columns:
    count = 0
    for j in df[i]:
        for k in ClassAttributes:
            if k == df['Class'][count]:
                if j in dff_data['Features']:
                    dff_data[k][dff_data['Features'].index(j)] = dff_data[k][dff_data['Features'].index(j)] + 1
                else:
                    dff_data['Features'].append(j)
                    for m in ClassAttributes:
                        if m == k:
                            dff_data[m].append(1)
                        else:
                            dff_data[m].append(0)
                break
        count = count + 1

dff = pd.DataFrame(dff_data)
# print('\n',dff)

dff1_data = {'Features':list(dff['Features']),'OnTime':[],'Late':[],'VeryLate':[],'Cancelled':[]}


for i in ClassAttributes:
    summ = dff[:4].sum()[i]
    for j in range(len(dff[i])):
        if summ != 0:
            if flsr(dff[i][j] / summ) != 0:
                dff1_data[i].append(flsr(dff[i][j] / summ))
            else:
                for v in attributes:
                    if dff['Features'][j] in v:
                        dff1_data[i].append(flsr((dff[i][j] + 1 ) / (len(v) + summ)))
        else:
            dff1_data[i].append(0)

dff1 = pd.DataFrame(dff1_data)

aa = dff[:4].sum()['OnTime']
bb = dff[:4].sum()['Late']
cc = dff[:4].sum()['VeryLate']
dd = dff[:4].sum()['Cancelled']


dff_temp = pd.DataFrame({'Features':['Total'],'OnTime':[flsr(aa/(aa+bb+cc+dd))],'Late':[flsr(bb/(aa+bb+cc+dd))],
                         'VeryLate':[flsr(cc/(aa+bb+cc+dd))],'Cancelled':[flsr(dd/(aa+bb+cc+dd))]})
dff2 = dff1.append(dff_temp,ignore_index=True)

# print('\n',dff2)

instancee = [x for x in input('Enter instance attributes and give space after each attribute Ex. Weekday Winter High None  =====  ').split()]

probability = {}

for i in ClassAttributes:
    probability[i] = flsr(dff2[i][list(dff['Features']).index(instancee[0])] * dff2[i][list(dff['Features']).index(instancee[1])] *
                          dff2[i][list(dff['Features']).index(instancee[2])] * dff2[i][list(dff['Features']).index(instancee[3])] *
                          dff2[i].iloc[-1])

sumb = sum(probability.values())

print('Normalized Probability of classes ','\n','OnTime = ',flsr(probability['OnTime']/sumb),
      '\n','Late = ',flsr(probability['Late']/sumb),'\n','VeryLate = ',flsr(probability['VeryLate']/sumb),'\n','Cancelled = ',
      flsr(probability['Cancelled']/sumb),'\n','\n','CLASS LABEL OF GIVEN INSTANCE IS ===   ',max(probability,key=probability.get).upper())
