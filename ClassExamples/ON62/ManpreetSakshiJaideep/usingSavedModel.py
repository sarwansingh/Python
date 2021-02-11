#using the model saved from hard disk 
import pickle 
# load the model from disk
filename = 'knnmodel.pkl'
loaded_model = pickle.load(open(filename, 'rb'))
P =[[55,	1,	156,	85,	140,	90,	0,	0,	1,	1]]
print(loaded_model.predict(P))
P =[[47,	1,	156,	56,	100,	60,	0,	0,	0,	2]]
print(loaded_model.predict(P))