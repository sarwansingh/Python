
from flask import Flask, render_template
 
app = Flask(__name__)

@app.route('/')
def homepage():
   
    try:
        return render_template("index.html")
    except Exception, e:
        return str(e)

if __name__ == "__main__":
	app.run()