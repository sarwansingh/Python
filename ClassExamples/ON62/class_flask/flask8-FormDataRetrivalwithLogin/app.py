from flask import *
from flask import Response
app = Flask(__name__)


@app.route('/')
def home ():
	ee = request.cookies.get('uemail')
	return render_template("login.html" , useremail = ee)
	
@app.route('/validate', methods = ["POST"])
def validate():
	if request.method == 'POST' and	request.form['pass'] == 'abc':
		em = request.form['email']
		resp = make_response(render_template('student.html'))
		resp.set_cookie('uemail', em)
   
		return resp
		
	return redirect(url_for("login"))
	
@app.route('/usuccess')
def usuccess():
	
	return render_template('student.html')

@app.route('/success',methods = ['POST', 'GET'])
def print_data():
	if request.method == 'POST':
		result = request.form
		return render_template("result_data.html",result = result)

if __name__ == '__main__':
	app.run(debug = True)