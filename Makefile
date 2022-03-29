check:
	g++ --version

test:
	g++ FileRedactor.cpp -c -o FileRedactor.o
	g++ unit_tests.cpp -o unit_test FileRedactor.o
	./unit_test

install:
	g++ FileRedactor.cpp -c -o FileRedactor.o
	g++ parser.cpp -c -o parser.o
	g++ file_redactor.cpp -o file_redactor FileRedactor.o parser.o

clean:
	rm unit_test || true
	rm UNIT_TEST || true
	rm FileRedactor.o || true
	rm parser.o || true