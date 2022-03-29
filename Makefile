check:
	g++ --version

test:
	g++ FileRedactor.cpp -c -o FileRedactor.o
	g++ unit_tests.cpp -o unit_test FileRedactor.o
	./unit_test

install:
	g++ FileRedactor.cpp -c -o FileRedactor.o
	g++ test.cpp -o a FileRedactor.o

clean:
	rm unit_test
	rm UNIT_TEST
	rm FileRedactor.o