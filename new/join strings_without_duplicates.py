s=["abc","bcd","def","eft"]
res=""
ind=''
for i in range(len(s)-1,0,-1):
    s1=s[i]
    s2=s[i-1]
    print(s1)
    print(s2)
    for j in range(len(s1)):
        if s1[j] not in s2:
            ind=j
            res=s1[j:]+res
            break
res=s[0]+res
print(res)