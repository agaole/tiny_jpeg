#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


#define TJE_IMPLEMENTATION
#include "tiny_jpeg.h"


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
void savefile(unsigned char* data, int width, int height, int num_components)
{
	int fd;
	int ret;
	fd = open("./save.pic",O_RDWR|O_CREAT, 0666);
	if(fd < 0){
		printf("open fail\n");
	}
	ret = write(fd, data, width*height*num_components);
	if(ret != width*height*num_components){
		printf("write fail ret=%d\n",ret);
	}
	close(fd);
}
	
int main()
{
    int width, height, num_components;
    unsigned char* data = stbi_load("in.bmp", &width, &height, &num_components, 0);
    if ( !data ) {
        puts("Could not find file");
        return EXIT_FAILURE;
    }
	printf("%d %d %d \n",width, height, num_components);
	savefile(data,width,height,num_components);
    if ( !tje_encode_to_file("out.jpg", width, height, num_components, data) ) {
        fprintf(stderr, "Could not write JPEG\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}