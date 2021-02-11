import pandas as pd
import numpy as np
import pickle
from sklearn.neighbors import KNeighborsClassifier
 
url = 'https://raw.githubusercontent.com/sarwansingh/Python/master/ClassExamples/data/HeartDisease_cardio_data.csv'
df = pd.read_csv(url , sep = ";")
print("reading file " ) 
df['age']=df['age']/365
print("cleaning data ")
df =df.drop( ['id','cholesterol', 'gluc'] , axis=1)
#create new column with standard values
df=df.assign(heartrate='60-200')
# assigning the values
df.loc[df['age'] >= 20 ,'heartrate'] = '100-170'
df.loc[df['age'] >= 30 ,'heartrate'] = '95-165'
df.loc[df['age'] >= 40  ,'heartrate'] = '90-155'
df.loc[df['age'] >= 50  ,'heartrate'] = '85-145'
df.loc[df['age'] >= 60  ,'heartrate'] = '80-140'
df.loc[df['age'] >= 70 ,'heartrate'] = '75-130'
#codification of column heartrate
df['heartrate'] = df['heartrate'].replace(['85-145', '90-155', '80-140', '95-165', '100-170' ],['1', '2', '3', '4', '5'])

df=df.dropna()
#convert the columns to int
df['weight']=df.weight.astype(int)
df['age']=df.age.astype(int)
df['heartrate']=df.heartrate.astype(int)
#realigning the columns 
df = df[['age' , 'gender',	'height','weight', 'ap_hi',	'ap_lo',	'smoke',	'alco',	'active',	'heartrate',	'cardio']]
print("making model" ) 
#creating model 
knnmodel = KNeighborsClassifier()
X = df.iloc[:,0:10 ]
y = df.iloc[:, -1]
#fit the model 
knnmodel.fit(X,y)
#predict
print ("using model for prediction" ) 
res = knnmodel.predict([[48,	2,	169,	82,	150,	100,	0,	0,	1, 4	]])
print( res  ) 
res= knnmodel.predict([[52 , 2,  168, 76, 120, 80, 1,  0,  1, 4]])
print( res)
print("prediction successful " ) 
print( " saving model " )
pickle.dump(knnmodel, open('knnmodel.pkl', 'wb') , protocol=2)

	