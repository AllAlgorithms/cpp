
# coding: utf-8

# In[ ]:


import numpy 

print("Enter the dimension of your world!")
p=int(input())

screen=numpy.random.uniform(round(0),round(1),(p,p))         # for random world generator
for i in range(0,p):
    for j in range (0,p):
        screen[i][j]=round(screen[i][j])
        
        
        
print(screen)        
area=0
print("Enter your co-ordinates")
x=int(input())
y=int(input())

n=int(p)

a=[0]*n
for i in range(n):
    a[i] = [0]*n
def countarea(x,y):                           #function for calculating area of continents
    global area

    if x<0 or x>=p or y<0 or y>=p:
        return ;
    if screen[x][y]==0:
        return ;
    if a[x][y]==1:
        return ;
    a[x][y]=1
    area=area+1
    
    countarea(x+1,y)
    countarea(x-1,y)
    countarea(x,y+1)
    countarea(x,y-1)
    countarea(x+1,y+1)
    countarea(x-1,y-1)
    countarea(x+1,y-1)
    countarea(x-1,y+1)
if screen[x][y]==0:
    print("You landed on an ocean!")
else:                   
    countarea(x,y)                                # for calculating area of user's continent
    print("The area of your continent is:",area)
for i in range(0,p):                              #for calculating area of other continents
    for j in range (0,p):
        global area
        area=0
        if screen[i][j]==1 and a[i][j]==0:
            countarea(i,j)
            print("Area of other continent/s: ",area)       
       
    

