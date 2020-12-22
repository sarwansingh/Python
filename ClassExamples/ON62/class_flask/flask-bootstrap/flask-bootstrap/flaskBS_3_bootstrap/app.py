from flask import *
app = Flask(__name__)

@app.route('/')
def abc():
	return  render_template('index.html')

@app.route('/contact')
def contact():
	return  render_template('contact.html')
	
if __name__ == '__main__':
	app.run(debug = True)