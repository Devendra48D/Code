#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <linux/kernel.h>
#include <linux/syscall.h>
#include <linux/unistd.h>
#include <linux/iofile.h>
#include <linux/errno.h>
#include <linux/fcntl.h>
#include <linux/linkage.h>
#include <libgen.h>
#include <sys/types.h>
#include <sys/stat.h>

long sys_cs401_set_attribute(char* filename, char *attrname, char *attrvalue, int size){
	char* name;


	unsigned int string_length = strlen_user(basename(filename)) + 7;

	name = (char*)malloc(string_length*sizeof(char));

	name = "." + basename(filename) + "_ttr/";

	char* path = dirname(filename)

	if (opendir(path) == NULL){
		mkdir(path, SIRUSR | S_IWUSR | S_IXUSR);	
	}	

	char* attribute_path = path + name + attrname;
	
	int fp = open(attribute_path, O_RDWR | Q_CREAT, S_IRUSR | S_IWUSR);

	write(fp, attrvalue, size);

	return 0;

}

long sys_cs401_get_attribute(char* filename, char *attrname, char *buf, int bufsize){



	char* name;

	//char* read;

	unsigned int string_length = strlen(basename(filename)) + 7;

	name = (char*)malloc(string_length*sizeof(char));

	name = "." + basename(filename) + "_attr/";

	char* directory_path = dirname(filename);

	char *attribute_path = directory_path + name + attrname;

	struct stat my_status;

	stat(attribute_path, &my_status);

	if ( access( attribute_path, F_OK) != -1){
		unsigned int size = my_status.st_size; 

		if (bufsize < size)
		{
			return -1; 
		}

		int file = open(attribute_path, O_RDWR);	

		return read(file, buf, bufsize);		
	}else{
		return -1;
	}

	

}

long sys_cs401_get_attribute_name(char *filename, char *buf, int bufsize){
	DIR *attribute_directory;

	struct dirent *dp;

	char* attribute_name;

	//char* read;

	unsigned int string_length = strlen(filename) + 7;

	attribute_name = (char*)malloc(string_length*sizeof(char));

	attribute_name = "." + basename(filename) + "_attr/";

	char* directory_path = dirname(filename);

	attribute_directory = opendir(directory_path + attribute_name);

	//this while loop was derievd from a post in stack overflow and discussed with ashok tamang and anurag rijal who also worked on the same project andwas the only group who worked ont this project. They were very helpfull throuhout the project. 

	while(dp = readdir(attribute_directory) != NULL && strlen(buf) < bufsize){
		if ( !strcmp(dp->d_name, ".") || !strcmp(dp->d_name, ".."))
		{}
		else{	
			buf += dp->d_name + ":";
		}	
	}

	closedir(attribute_directory);

	return 0;


}

long sys_cs401_remove_attribute(char *filename, char *attrname){
	char* name;

	unsigned int string_length = strlen(filename) + 7;

	attribute_name = (char*)malloc(string_length*sizeof(char));

	attribute_name = "." + basename(filename) + "_attr/";

	attribute_dir_path = dirname(filename);

	char* attribute_path = attribute_dir_path + attribute_name + attrname; 

	//same as above while loop
	if (statis_remove_dir == 0){
		return 0;
	}
	else{
		return remove(attribute_path)
	}
		
}

