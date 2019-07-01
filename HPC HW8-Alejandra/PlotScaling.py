import numpy as np
import matplotlib.pyplot as plt
##Initial values
serial_time=22.003
threat_number=[1.,2.,3.,4.]
parallel_time=[8.334,5.362,6.151,7.461]
threat_time=[]
f=[]
##Serial fraction and threat time calculation
for i in range(0,len(threat_number)):
	threat_time.append(parallel_time[i]/threat_number[i])
	f.append(serial_time/(serial_time+parallel_time[i]))
##PLot
fig,ax=plt.subplots()
plt.plot(threat_number,threat_time,'o--')
ax.set(xlabel='Number of threats', ylabel='Time of threat (seconds)',
       title='Scaling Plot')
ax.grid()
fig.savefig("scaling.png")
plt.show()

print('Threat_time',threat_time)
print('serial_fraction',f)
