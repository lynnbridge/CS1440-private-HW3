#include <iostream>

#include "Report.hpp"
#include "Sort.hpp"
#include "Stats.hpp"
#include "Database.hpp"

// include header files as needed


int main(void) {
	Report rpt;
	//calculate size all intdustries
	rpt.all.total_wages = total_annual_wages(all_industries);
	rpt.all.total_employment = total_employment_level(all_industries);
	rpt.all.per_capita_wage = per_capita_annual_wages(all_industries);
	
	int size = 0;
	while(all_industries[size].area_fips != "END") size++; 
	size++;
	
	//sort all industries top annual wages
	sort_employment_by_total_annual_wages(all_industries, size);
	for(int i = 0; i < TOP_N; i++){
		rpt.all.top_annual_wages[i].stat = all_industries[i].total_annual_wages;
		rpt.all.top_annual_wages[i].area_title = area_fips_To_area_title(fips_areas, all_industries[i].area_fips);
	}
	//bottom wages
	for(int i = 0; i < TOP_N; i++){
		rpt.all.bot_annual_wages[i].stat = all_industries[size - 2 - i].total_annual_wages;
		rpt.all.bot_annual_wages[i].area_title = area_fips_To_area_title(fips_areas, all_industries[size - 2 - i].area_fips);
	}
	sort_employment_by_annual_avg_emplvl(all_industries, size);
	//Top 5 areas by annual Average Employment
	for(int i = 0; i < TOP_N; i++){
		rpt.all.top_annual_avg_emplvl[i].stat = all_industries[i].annual_avg_emplvl;
		rpt.all.top_annual_avg_emplvl[i].area_title = area_fips_To_area_title(fips_areas, all_industries[i].area_fips);
	}
	//Bottom 5
	for(int i = 0; i < TOP_N; i++){
		rpt.all.bot_annual_avg_emplvl[i].stat = all_industries[size - 2 - i].annual_avg_emplvl;
		rpt.all.bot_annual_avg_emplvl[i].area_title = area_fips_To_area_title(fips_areas, all_industries[size - 2 - i].area_fips);
	}
	
	
	
	
	//calculate size soft_publishing fips area array and then specific area fips looking for
	rpt.soft.total_wages = total_annual_wages(software_publishing);
	rpt.soft.total_employment = total_employment_level(software_publishing);
	rpt.soft.per_capita_wage = per_capita_annual_wages(software_publishing);
	
	size = 0;
	while(software_publishing[size].area_fips != "END") size++; 
	size++;
	
	//sort soft industries top annual wages
	sort_employment_by_total_annual_wages(software_publishing, size);
	for(int i = 0; i < TOP_N; i++){
		rpt.soft.top_annual_wages[i].stat = software_publishing[i].total_annual_wages;
		rpt.soft.top_annual_wages[i].area_title = area_fips_To_area_title(fips_areas, software_publishing[i].area_fips);
	}
	//bottom wages
	for(int i = 0; i < TOP_N; i++){
		rpt.soft.bot_annual_wages[i].stat = software_publishing[size - 1 - i].total_annual_wages;
		rpt.soft.bot_annual_wages[i].area_title = area_fips_To_area_title(fips_areas, software_publishing[size - 1 - i].area_fips);
	}
	sort_employment_by_annual_avg_emplvl(software_publishing, size);
	//Top 5 areas by annual Average Employment
	for(int i = 0; i < TOP_N; i++){
		rpt.soft.top_annual_avg_emplvl[i].stat = software_publishing[i].annual_avg_emplvl;
		rpt.soft.top_annual_avg_emplvl[i].area_title = area_fips_To_area_title(fips_areas, software_publishing[i].area_fips);
	}
	//Bottom 5
	for(int i = 0; i < TOP_N; i++){
		rpt.soft.bot_annual_avg_emplvl[i].stat = software_publishing[size - 1 - i].annual_avg_emplvl;
		rpt.soft.bot_annual_avg_emplvl[i].area_title = area_fips_To_area_title(fips_areas, software_publishing[size - 1 - i].area_fips);
	}
	

	std::cout << rpt << std::endl;
}
