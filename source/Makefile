SRCS    = $(shell /bin/ls *.cc)
CFLAGS   = -DOP_ASSIGN

.SUFFIXES: $(SUFFIXES) .cpp

%.o: %.cpp
	g++ -c $(CFLAGS) -fno-elide-constructors $<

OBJS = global_map.o op_ceiling.o op_if.o op_plus.o op_floor.o \
       op_substraction.o op_multiply.o op_division.o op_quote.o \
       op_nullp.o op_cons.o op_car.o op_cdr.o\
       op_lessthan.o op_not.o op_print.o op_eval.o\
       op_define.o op_lambda.o op_apply.o\
       SymbolDecider.o\
       Cell.o ProcedureCell.o\
       main.o parse.o eval.o

main: $(OBJS)
	g++ -g $(CFLAGS) -o $@ $(OBJS) -lm

global_map.o: Cell.hpp global_map.hpp global_map.cpp
	g++ -c -g global_map.cpp

op_ceiling.o: SymbolOperator.hpp cons.hpp Cell.hpp eval.hpp op_ceiling.hpp \
op_ceiling.cpp
	g++ -c -g op_ceiling.cpp

op_if.o: SymbolOperator.hpp cons.hpp Cell.hpp eval.hpp op_if.hpp op_if.cpp
	g++ -c -g op_if.cpp

op_plus.o: SymbolOperator.hpp cons.hpp Cell.hpp eval.hpp op_plus.hpp op_plus.cpp
	g++ -c -g op_plus.cpp	

op_floor.o: SymbolOperator.hpp cons.hpp Cell.hpp eval.hpp op_floor.hpp \
op_floor.cpp
	g++ -c -g op_floor.cpp

op_substraction.o: SymbolOperator.hpp cons.hpp Cell.hpp eval.hpp \
op_substraction.hpp op_substraction.cpp
	g++ -c -g op_substraction.cpp

op_multiply.o: SymbolOperator.hpp cons.hpp Cell.hpp eval.hpp op_multiply.hpp \
op_multiply.cpp
	g++ -c -g op_multiply.cpp

op_divison.o: SymbolOperator.hpp cons.hpp Cell.hpp eval.hpp op_divison.hpp \
op_divison.cpp
	g++ -c -g op_divison.cpp	

op_quote.o: SymbolOperator.hpp cons.hpp Cell.hpp eval.hpp op_quote.hpp \
op_quote.cpp
	g++ -c -g op_quote.cpp

op_nullp.o: SymbolOperator.hpp cons.hpp Cell.hpp eval.hpp op_nullp.hpp \
op_nullp.cpp
	g++ -c -g op_nullp.cpp

op_cons.o: SymbolOperator.hpp cons.hpp Cell.hpp eval.hpp op_cons.hpp op_cons.cpp
	g++ -c -g op_cons.cpp

op_car.o: SymbolOperator.hpp cons.hpp Cell.hpp eval.hpp op_car.hpp op_car.cpp
	g++ -c -g op_car.cpp

op_cdr.o: SymbolOperator.hpp cons.hpp Cell.hpp eval.hpp op_cdr.hpp op_cdr.cpp
	g++ -c -g op_cdr.cpp

op_lessthan.o: SymbolOperator.hpp cons.hpp Cell.hpp eval.hpp op_lessthan.hpp \
op_lessthan.cpp
	g++ -c -g op_lessthan.cpp

op_not.o: SymbolOperator.hpp cons.hpp Cell.hpp eval.hpp op_not.hpp op_not.cpp
	g++ -c -g op_not.cpp

op_print.o: SymbolOperator.hpp cons.hpp Cell.hpp eval.hpp op_print.hpp \
op_print.cpp
	g++ -c -g op_print.cpp

op_eval.o: SymbolOperator.hpp cons.hpp Cell.hpp eval.hpp op_eval.hpp op_eval.cpp
	g++ -c -g op_eval.cpp	

op_define.o: SymbolOperator.hpp cons.hpp Cell.hpp global_map.hpp eval.hpp \
op_define.hpp op_define.cpp
	g++ -c -g op_define.cpp
	
op_lambda.o: SymbolOperator.hpp cons.hpp Cell.hpp global_map.hpp eval.hpp \
op_lambda.hpp op_lambda.cpp
	g++ -c -g op_lambda.cpp		
	
op_apply.o: SymbolOperator.hpp cons.hpp Cell.hpp global_map.hpp eval.hpp \
op_apply.hpp op_apply.cpp
	g++ -c -g op_apply.cpp		

SymbolDecider.o: SymbolOperator.hpp SymbolDecider.hpp SymbolDecider.cpp
	g++ -c -g SymbolDecider.cpp

Cell.o: Cell.hpp IntCell.hpp DoubleCell.hpp SymbolCell.hpp ConsCell.hpp \
ProcedureCell.hpp SymbolOperator.hpp Cell.cpp
	g++ -c -g Cell.cpp

ProcedureCell.o: Cell.hpp ProcedureCell.hpp global_map.hpp eval.hpp\
ProcedureCell.cpp
	g++ -c -g ProcedureCell.cpp
	
eval.o: Cell.hpp IntCell.hpp DoubleCell.hpp SymbolCell.hpp ConsCell.hpp \
global_map.hpp cons.hpp eval.hpp eval.cpp
	g++ -c -g eval.cpp

parse.o: eval.o parse.hpp parse.cpp
	g++ -c -g parse.cpp

main.o: Cell.hpp cons.hpp parse.o eval.o main.cpp
	g++ -c -g main.cpp

doc:
	doxygen doxygen.config

test:
	rm -f testoutput.txt
	./main testinput.txt > testoutput.txt
	diff testreference.txt testoutput.txt

test2:
	rm -f testoutput2.txt
	./main testinput_more_operators.txt > testoutput2.txt
	diff testinput_more_operators_result.txt testoutput2.txt

test3:
	rm -f testoutput3.txt
	./main testinput_a2_step5.txt > testoutput3.txt
	diff testinput_a2_step5_result.txt testoutput3.txt

clean:
	rm -f core *~ $(OBJS) main main.exe testoutput.txt

rebuild:
	make clean
	make
