build-stack:
	gcc ./src/bdd.c -o ./output/bdd
	gcc ./src/server.c -o ./output/server
	gcc ./src/client.c -o ./output/client

bdd:
	gcc ./src/bdd.c -o ./output/bdd

server:
	gcc ./src/server.c -o ./output/server
	./output/server

client:
	gcc ./src/client.c -o ./output/client
	./output/client

clean:
	rm output/*
