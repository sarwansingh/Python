from flask import *
app = Flask(__name__)
@app.route('/admin')
def admin():
	return ' Your are admin'
@app.route('/librarion')
def librarion():
	return 'You are librarion'
@app.route('/student')
def student():
	return 'You are student'

@app.route('/user/<name>')
def user(name):
	if name == 'admin':
		return redirect(url_for('admin'))
	if name == 'librarion':
		return redirect(url_for('librarion'))
	if name == 'student':
		return redirect(url_for('student'))

if __name__ =='__main__':
	app.run(debug = True)