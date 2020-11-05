function echoho
{
#edit time
	sleep 10;
#edit prog name
	firefox;
}

function sendErr
{
	gccCom="gcc"
	fileName=""
	existingFileName=""
	sourceReg=""
	user=$(whoami)
	filePathNew="./"$user"/new/"
	filePathOld="./"$user"/old/"
	errFile="err.er"
	for i in `seq $#`
	do
		if [[ ${!i} =~ .+\.c ]]; then
			fileName="${!i}"
		fi
		gccCom="$gccCom ${!i}"
	done
	$gccCom;
	echoho &
	if [[ ! -e $filePathNew ]]; then
		mkdir -p $filePathNew;
		$gccCom &> $filePathNew$errFile;
		cp $fileName $filePathNew$fileName;
	elif [[ -e $filePathNew && ! -e $filePathOld ]]; then
		existingFileName=$(echo "${filePathNew}*.c")
		existingFileName=$(echo $existingFileName)
		sourceReg="${existingFileName##*/}"
		if [[ "$sourceReg" == "$fileName" ]]; then
			mv $filePathNew $filePathOld;
			mkdir -p $filePathNew;
			$gccCom &> $filePathNew$errFile;
			cp $fileName $filePathNew$fileName;
			diff $filePathOld$fileName $filePathNew$fileName > "./"$user"/sourcediff.diff";
		else
			rm -r $filePathNew;
			mkdir -p $filePathNew;
			$gccCom &> $filePathNew$errFile;
			cp $fileName $filePathNew$fileName;
		fi
	else
		existingFileName=$(echo "${filePathNew}*.c")
		existingFileName=$(echo $existingFileName)
		sourceReg="${existingFileName##*/}"
		if [[ "$sourceReg" == "$fileName" ]]; then
			rm -r $filePathOld;
			mv $filePathNew $filePathOld;
			mkdir -p $filePathNew;
			$gccCom &> $filePathNew$errFile;
			cp $fileName $filePathNew$fileName;
			diff $filePathOld$fileName $filePathNew$fileName > "./"$user"/sourcediff.diff";
		else
			rm -r $filePathNew;
			rm -r $filePathOld;
			rm "./"$user"/sourcediff.diff";
			mkdir -p $filePathNew;
			$gccCom &> $filePathNew$errFile;
			cp $fileName $filePathNew$fileName;
		fi
	fi
}
alias gcc=sendErr
