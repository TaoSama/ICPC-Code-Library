# import os
# workpath = r'E:\ACM\Problem Data\Training Problems\33'
# for dirs in os.listdir(workpath):
#     if os.path.isdir(os.path.join(workpath, dirs)):
#         print dirs
#         a = int(dirs) - 4520 + 25046
#         os.rename(os.path.join(workpath, dirs), os.path.join(workpath, str(a)))

# workpath = r'C:\Users\TaoSama\Desktop\Final\data'
# for i in xrange(25026, 25033):
#     os.mkdir(os.path.join(workpath, `i`))



x, n = input().split()
x = float(x)
n = int(n)
print x**n
