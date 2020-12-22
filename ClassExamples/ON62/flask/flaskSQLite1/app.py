from flask import Flask, render_template, request, redirect, url_for, flash
from flask_sqlalchemy import SQLAlchemy 
import os

app = Flask(__name__)
app.secret_key = "Secret Key"

path = os.path.abspath( os.path.dirname(__file__))
app.config['SQLALCHEMY_DATABASE_URI'] = "sqlite:///" + os.path.join(path , 'database.sqlite')
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

db = SQLAlchemy(app)

class Crud(db.Model):
	id = db.Column(db.Integer , primary_key = True)
	name = db.Column(db.String(100))
	email = db.Column(db.String(100))
	phone = db.Column(db.String(100))
	
	#constructor 
	def __init__(self, name, email, phone):
		self.name = name
		self.email = email
		self.phone = phone
		

@app.route('/')  
def msg():	
	all_data = Crud.query.all()
	return render_template("first.html", all_data = all_data)

if __name__ == '__main__':  
   app.run(debug = True)  