TARGET = svr cli
all : $(TARGET)

svr : tcp_select_svr.c
gcc $ ^ -o $@
cli : tcp_seletc_client.c
gcc $ ^ -o $@

clean :
	rm - f $(TARGET)


