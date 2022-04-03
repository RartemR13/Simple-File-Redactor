check:
	g++ --version

test:
	g++ DTree/unit/unit_test.cpp -o DTree/unit/unit_test
	./DTree/unit/unit_test
	g++ DTree/stress/stress_test.cpp -o DTree/stress/stress_test
	bash DTree/stress/stress.bash

	g++ FileRedactor.cpp -c -o FileRedactor.o
	g++ unit_tests.cpp -o unit_test FileRedactor.o
	./unit_test

install:
	g++ FileRedactor.cpp -c -o FileRedactor.o
	g++ parser.cpp -c -o parser.o
	g++ file_redactor.cpp -o file_redactor FileRedactor.o parser.o

clean:
	rm DTree/stress/stress_test || true
	rm DTree/unit/unit_test || true
	rm out || true

	rm unit_test || true
	rm UNIT_TEST || true
	rm FileRedactor.o || true
	rm parser.o || true