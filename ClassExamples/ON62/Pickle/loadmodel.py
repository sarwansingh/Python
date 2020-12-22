 
import pickle 
#SPFKnnModel
filename = "SPFKnnModel.pkl"
loaded_model = pickle.load(open(filename, "rb"))
P =[[7,27]]
print(loaded_model.predict(P))
P =[[2,43]]
print(loaded_model.predict(P))