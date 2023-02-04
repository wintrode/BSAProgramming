import sys

thepassword = "purple"
guessed = False

while not guessed :
   sys.stdout.write("Guess the password: ")
   sys.stdout.flush()
   word  = sys.stdin.readline()
   
   if word.strip() == thepassword :
       print("C'mon in.")
       guessed = True
   else :
       if word[0] == thepassword[0] :
          print("hmmm,  you got the first letter right, try again.")
       else :
          print("not even close.")
          if len(word) == 0 :
              break
       #
   #

#

if not guessed :
    print("ok, so you give up.  Scram!")
