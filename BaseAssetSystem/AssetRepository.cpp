#include "AssetRepository.h"
#include "CommandHandler.h"
#include "AssetManager.h"

void AssetRepository::save(const std::vector<Asset>& assets) {
	std::ofstream out;
	out.open("C:\\Users\\Roman\\source\\repos\\BaseAssetSystem\\AssetData.txt");
	if (out.is_open()) {
		//out << "Test save\n";
		for (const auto& asset : assets) {
			out << asset.getId() << ";"
				<< asset.getName() << ";"
				<< asset.getCategory() << ";"
				<< asset.getLocation() << ";"
				<< asset.getValue() << ";"
				<< asset.getYearsOfUsing() << ";" << std::endl;
		}
	}
	out.close();
}


void AssetRepository::load(AssetManager& m) {
	std::string bufferLine;
	std::string _id;
	std::string _name;
	std::string _category;
	std::string _location;
	std::string _value;
	std::string _yearsOfUsing;

	std::ifstream in("C:\\Users\\Roman\\source\\repos\\BaseAssetSystem\\AssetData.txt");
	if (in.is_open())
	{ 
		while (std::getline(in, bufferLine)) {
			std::stringstream ss(bufferLine);
			std::getline(ss, _id, ';');
			std::getline(ss, _name, ';');
			std::getline(ss, _category, ';');
			std::getline(ss, _location, ';');
			std::getline(ss, _value, ';');
			std::getline(ss, _yearsOfUsing);

			m.addAsset(_name, _category, _location, std::stod(_value), std::stoi(_yearsOfUsing));
		}
	}
}