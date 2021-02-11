#app.py
from flask import Flask,request, url_for, redirect, render_template
import pickle
import numpy as np

app = Flask(__name__)
model=pickle.load(open('knnmodel.pkl','rb'))

@app.route('/')
def home():
    return render_template("index.html")

@app.route('/predict',methods=['POST','GET'])
def predict():
    # receive the values send by user in three text boxes thru request object -> requesst.form.values()
    
	int_features = [int(x) for x in request.form.values()]
	final_features = [np.array(int_features)]
	
	#print(final_features)
	
	#final_features =  [[52 , 2,  168, 76, 120, 80, 1,  0,  1, 4]] 
	#[[48,	2,	169,	82,	150,	100,	0,	0,	1, 4	]]   
	
	prediction=model.predict_proba(final_features)
	output='{0:.{1}f}'.format(prediction[0][1], 2)
   
	return render_template('index.html', pred='Heart Disease probability is :  {}'.format(output))
	#return render_template('index.html', pred= final_features)

if __name__ == '__main__':
    app.run(debug=False)
