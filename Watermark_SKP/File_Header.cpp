#include "File_Header.h"

const size_t InfoHeaderSize = 40;
const size_t FileHeaderSize = 14;


void File_Header::InitializeHeader(Reader* _r)
{
	//memcpy((void*)this->signature[0], (void*)this->data[0], sizeof(this));
	
	//signature[0] = _r->data[0];
	//signature[1]=_r->data[1];
	//file_size[0]=_r->data[2];
	//file_size[1]=	_r->data[3];
	//file_size[2]=	_r->data[4];
	//file_size[3]=	_r->data[5];
	//reserved[0]=_r->data[6];
	//reserved[1]=_r->data[7];
	//reserved[2]=_r->data[8];
	//reserved[3]=_r->data[9];
	memcpy(&signature[0], &_r->data[0], FileHeaderSize);//jestem jebanym kurwa zwierzeciem XDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
	/*memcpy(&signature,&_r->data[0], sizeof(signature));
	size_t current_Size = sizeof(signature);
	memcpy(&file_size[0], &_r->data[current_Size], sizeof(file_size));
	 current_Size += sizeof(file_size);
	memcpy(&reserved[0], &_r->data[current_Size], sizeof(reserved));
	current_Size += sizeof(reserved);
	memcpy(&data_offset[0], &_r->data[current_Size], sizeof(data_offset));*/
	Byte_reverse(file_size, sizeof(file_size));
	//int mycastint = reinterpret_cast<int>(file_size);
	uint32_t Casted_file_size=Hex_Arr_To_Int(file_size);

	std::cout << "size: " << Casted_file_size << std::endl;

	Byte_reverse(reserved,sizeof(reserved));

}

size_t GetDataOffset(File_Header& fh)
{

	Byte_reverse(fh.data_offset, sizeof(fh.data_offset));
	size_t index = Hex_Arr_To_Int(fh.data_offset);
	return index;
}
