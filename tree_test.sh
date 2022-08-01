gcc -lreadline -lohw -L/usr/local/opt/readline/lib -L./libohw -I./libohw/incs -I/usr/local/opt/readline/include \
	 ./tree/print.c ./tree/tree.c ./tree/utils.c ./tree/find.c ./tree/advlst.c ./tree/destroy.c ./tree/extract.c ./tree/new_data.c \
	 ./tree/translate.c ./tree/strings.c ./tree/tree_test.c \
	-o tree_test && ./tree_test
