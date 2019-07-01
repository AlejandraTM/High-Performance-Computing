
import subprocess
import os
    # create a pipe to a child process 
data, temp = os.pipe() 
  
    # write to STDIN as a byte object(covert string 
    # to bytes with encoding utf8) 
os.write(temp, bytes("5 10\n", "utf-8")); 
os.close(temp) 
  
    # store output of the program as a byte string in s 
s = subprocess.check_output("g++ code.cpp -o code;./code", stdin = data, shell = True) 
  
    # decode s to a normal string 
print(s.decode("utf-8")) 


