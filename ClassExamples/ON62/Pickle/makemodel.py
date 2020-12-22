dataurl = "https://raw.githubusercontent.com/sarwansingh/Python/master/ClassExamples/data/student-pass-fail-data.csv"
import pandas as pd
import pickle
from sklearn.neighbors import KNeighborsClassifier

dfStu = pd.read_csv(dataurl)

X = dfStu.iloc[:,:2 ]
print(X.shape , X [:10])

y = dfStu.iloc[:,2]
print(y.shape, y[:10])

SPFknnmodel = KNeighborsClassifier()

SPFknnmodel.fit(X,y)

# saving the model on Hard disk

filename = 'SPFKnnModel.pkl'
pickle.dump(SPFknnmodel, open(filename, 'wb') )