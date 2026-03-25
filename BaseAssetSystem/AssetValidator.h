#pragma once
#include <string>


class AssetValidator
{
public:
	AssetValidator() = default;

	std::string validateName(const std::string& name) const;
	std::string validateCategory(const std::string& category) const;
	std::string validateLocation(const std::string& location) const;
	std::string validateValue(const double value) const;
	std::string validateYearsOfUsing(const int years) const;

private:
	static constexpr size_t MAX_NAME_LENGTH = 50;
	static constexpr size_t MAX_LOCATION_LENGTH = 50;
	static constexpr size_t MAX_CATEGORY_LENGTH = 30;
	static constexpr double MAX_VALUE = 999999999999.0;
	static constexpr size_t MAX_YEARS_OF_USING = 500;

};

