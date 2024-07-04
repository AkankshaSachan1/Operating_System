cc=gcc

copy_student_data: copy_student_data.o file_write.o
			gcc student_data copy_student_data.o file_write.o

copy_student_data.o: copy_student_data.c
					gcc -c copy_student_data.c

file_write.o: file_write.c
			gcc -c file_write.c