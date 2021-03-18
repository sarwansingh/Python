from flask import *

app = Flask(__name__)
 

@app.route('/')
def home():
	return " Hi Champs of AIML "

@app.route('/table/<int:num>')
def table(num):
	return render_template('table.html',n=num)

if __name__ == '__main__':
	app.run()