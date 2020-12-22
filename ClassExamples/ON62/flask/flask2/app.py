from flask import *  

app = Flask(__name__)  

@app.route('/')  
def msg():
	return " I am index " 

@app.route('/file')
def openfile():
	return render_template("first.html")

@app.route('/html')
def message():  
      return "<html><body><h1>Hi, welcome to the website</h1></body></html>"  

if __name__ == '__main__':  
   app.run(debug = True)  