@ECHO OFF
FOR /L %%i IN (0,1,10) DO (
	C > input.txt
	A < input.txt > output1.txt
	F < input.txt > output2.txt
	
	fc /b output1.txt output2.txt > nul
	if errorlevel 1 (
	    echo different
	) else (
	    echo same
	)
)