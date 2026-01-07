gen:
	python3 ./example.py 
	gcc -o ex main.c -lm

clean:
	rm ./f.c ex
