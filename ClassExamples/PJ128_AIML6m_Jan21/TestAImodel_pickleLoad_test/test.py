import pickle  
import numpy as np

# load the saved model file and use for prediction
logit_model = pickle.load(open('logit_modelp.pkl','rb'))  

ex2 = np.array([6.2,3.4,5.4,2.3]).reshape(1,-1)
print ( logit_model.predict(ex2) ) 