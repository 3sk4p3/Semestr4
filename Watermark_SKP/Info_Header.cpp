#include "Info_Header.h"

const size_t InfoHeaderSize = 40;
const size_t FileHeaderSize = 14;
void Info_Header::InitializeHeader(Reader* _r)
{
	memcpy(&Size, &_r->data[FileHeaderSize],InfoHeaderSize);
	Byte_reverse(Size,sizeof(Size));
	uint32_t Casted_Size = Hex_Arr_To_Int(Size);

	std::cout << "size: " << Casted_Size << std::endl;
}
uint32_t Info_Header::GetColorUsed()
{
	Byte_reverse(ColorUsed, sizeof(ColorUsed));
	uint32_t Casted_ColorUsed= Hex_Arr_To_Int(ColorUsed);
	return Casted_ColorUsed;

}
uint32_t Info_Header::GetWidth()
{
	Byte_reverse(Width, sizeof(Width));
	uint32_t Casted_WidthUsed = Hex_Arr_To_Int(Width);
	return Casted_WidthUsed;


}
uint32_t Info_Header::GetHeight()
{
	Byte_reverse(Height, sizeof(Height));
	uint32_t Casted_HeightUsed = Hex_Arr_To_Int(Height);
	return Casted_HeightUsed;
}
//1 2 3 4 ->size =4
//1 2 3 4| 5 6 7