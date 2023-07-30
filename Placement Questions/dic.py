s="abc"
dic={}
for i in s:
    if i not in dic:
       dic[i]=1
    else:
       dic[i]+=1
for i,j in dic.items():
    print(i,j)
print(pow(2,3))
print(2**3)
print(round(4.5))
print("-".join("hello world"))

l=["11","111","11111"]
print(list(map(len,l)))
