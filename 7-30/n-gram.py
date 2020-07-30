import sys
import math

#Delet space and tabs from souce code.
def delSpace( fileStr ):
	tmp=''
	for i in range(len(fileStr)):
		if( fileStr[i]==' ' or fileStr[i]=='\n' or fileStr[i]=='\t' ):
			tmp=tmp+''
		else:
			tmp=tmp+fileStr[i]
	return(tmp)

#Create n-gram array.
def toArray( n , fileStr ):
	tmp=[]

	for i in range(len(fileStr)-1):
		tmp.append(fileStr[i:i+eval(n)])

	return(tmp)

#Create n-gram dictionary.
#ex)
#	2-gram is ["ab","bc","ca","ab","bc","cc"]
#	then the dictionary of 2-gram is
#	{"ab":2,"bc":2,"ca":1,"cc":1}
def nGramDic( array ):
	tmpDic={}

	for i in range(len(array)):
		if( array[i] in tmpDic.keys() ):
			tmpDic[array[i]]+=1
		else:
			tmpDic[array[i]]=1

	return(tmpDic)

#Return length of vector.
def retVecLen( dic ):
	length=0

	for key,val in dic.items():
		length+=(val**2)
	length=math.sqrt(length)

	return(length)

#Return inner product.
def retInnerProduct( dicOne , dicTwo ):
	innerProduct=0

	for keyOne,valOne in dicOne.items():
		for keyTwo,valTwo in dicTwo.items():
			if( keyOne==keyTwo ):
				innerProduct+=(valOne*valTwo)

	return(innerProduct)

#Return cosine similarity.
def retCosSim( dicOne , dicTwo ):
	return( retInnerProduct(dicOne,dicTwo)/(retVecLen(dicOne)*retVecLen(dicTwo)) )

def main( n , file1 , file2 ):
	with open(file1,mode='r') as f:
		strOne=f.read()
	with open(file2,mode='r') as f:
		strTwo=f.read()
	
	modStrOne=delSpace(strOne)
	modStrTwo=delSpace(strTwo)

	strArrayOne=toArray(n,modStrOne)
	strArrayTwo=toArray(n,modStrTwo)

	strDicOne=nGramDic(strArrayOne)
	strDicTwo=nGramDic(strArrayTwo)

	print(retCosSim(strDicOne,strDicTwo))

if(__name__=="__main__"):
	main( sys.argv[1] , sys.argv[2] , sys.argv[3] )
