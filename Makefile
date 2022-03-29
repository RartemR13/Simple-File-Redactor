check:
	g++ --version

install:
	g++ FileRedactor.cpp -c -o FileRedactor.o
	g++ test.cpp -o a FileRedactor.o