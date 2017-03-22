#pragma once 

int file_get_descriptor ( char * f_name );

struct stat *file_get_statistic ( int f_descriptor );

void * file_display_vmem ( int f_descriptor , struct stat *stat );

void file_parse_to_array ( char * file , struct stat *f_stat , Array * arr );

