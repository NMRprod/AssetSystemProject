#include "AssetValidator.h"
//validateAsset(...).
//Проверка загружаемых из файла данных — метод должен работать как для новых объектов, так и для объектов после загрузки.

std::string AssetValidator::validateName(const std::string& name) const {
	if(name.empty()) {
		return "You didn't enter name!";
	}
	if(name.size() > MAX_NAME_LENGTH) {
		return "Asset name contain more than " + std::to_string(MAX_NAME_LENGTH) + " symbols!";
	}
	return "";
}

std::string AssetValidator::validateCategory(const std::string& category) const {
	if(category.empty()) {
		return "You didn't enter category!";
	}
	if(category.size() > MAX_CATEGORY_LENGTH) {
		return "Category name contain more than " + std::to_string(MAX_CATEGORY_LENGTH) + " symbols!";
	}
	return "";
}

std::string AssetValidator::validateLocation(const std::string& location) const {
	if(location.empty()) {
		return "Вы указали пустое место хранения!";
	}
	if (location.size() > MAX_LOCATION_LENGTH) {
		return "Location name contain more than " + std::to_string(MAX_LOCATION_LENGTH) +  " symbols!";
	}
	return "";
}

std::string AssetValidator::validateValue(const double value) const {
	if(value <= 0) {
		return "Asset value less or equal zero!";
	}
	if (value > MAX_VALUE) {
		return "The value of the asset exceeds the acceptable limit!";
	}
	return "";
}

std::string AssetValidator::validateYearsOfUsing(const int years) const {
	if (years < 0) {
		return "The usage period is less than zero!";
	}
	if (years >= MAX_YEARS_OF_USING) {
		return "The usage period exceeds the acceptable limit!";
	}
	return "";
}