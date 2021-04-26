# ===========
#   Imports
# ===========
import sqlite3 as sql

# ========================
#  Connecting to database
# ========================
conn = sql.connect("test.db")
cur = conn.cursor()

# =================
#  Query execution
# =================
query = ('''CREATE TABLE USERS2
    (username TEXT NOT NULL,
     email TEXT Primary key,
     password TEXT NOT NULL,
     contact  INT);''')
cur.execute(query)

# ================================
#  Closing connection to database
# ================================
conn.close()
