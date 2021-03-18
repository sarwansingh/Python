from flask import *

app = Flask(__name__)
 

@app.route('/')
def home():
	return " Hi Champs of AIML "

@app.route('/wel/<uname>')
def welcome(uname):
	return render_template('welcome.html',name=uname)

if __name__ == '__main__':
	app.run()