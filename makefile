view-table: main.cpp
	g++ -o view-table main.cpp -lncursesw

clean:
	rm -rf *.o view-table
