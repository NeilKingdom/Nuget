/**
 * The page is a collection of columns
 * The columns are a collection of cells
 * Each cell contains a string, but can only display a limited number of characters
*/

#ifndef FILEIO_H
#define FILEIO_H

#include <stddef.h>
#include <stdint.h>

#include "display.h"

#define MAX_DATA  30
/* DEF_ROWS/DEF_COLS just refer to the number of cells that get populated in defaults.conf */
#define DEF_ROWS  15
#define DEF_COLS  25
#define DEF_CONF 	"default"
#define PG_START 	"[Page Start]"
#define PG_END	  	"[Page End]"
#define COL_START "[Col Start]"
#define COL_END	"[Col End]"
#define NUL_ENTRY	'0'
#define PATH_LIM  256

typedef struct {
	size_t size;  /* TODO: if this is strlen or col_width, I don't see why it's necessary */
	char	 *data;
} cell;

typedef struct {
	uint16_t col_offset;
	uint16_t row_offset;
	cell	 	page_cells[MAX_OFSCR_COLS][MAX_OFSCR_ROWS];
} page;

static char* const top_row[] = { 
   "Jan Est", "Jan Act", "Feb Est", "Feb Act",
   "Mar Est", "Mar Act", "Apr Est", "Apr Act",
   "May Est", "May Act", "Jun Est", "Jun Act",
   "Jul Est", "Jul Act", "Aug Est", "Aug Act",
   "Sep Est", "Sep Act", "Oct Est", "Oct Act",
   "Nov Est", "Nov Act", "Dec Est", "Dec Act",
};

static char* const first_col[] = {
   "Profits", "", "Work", "Gifts", "Other", "",
   "Expenses", "", "Food", "Gas", "Hair Cuts", "Clothing", "Personal", "Hobby", "Other"	
};

/* Functions */
int  create_def_config(void);
int  create_config(dimensions *dims, char *year);
int  load_config(page *page_p, dimensions *dims, char *year);
int  page_init(page *page_p, dimensions *dims);
int  page_cleanup(page *page_p);
void print_onscr_conf_debug(page pg, dimensions *dims);
void redraw(page pg, dimensions *dims, char *year);
bool check_existing(char *fname);

#endif /* FILEIO_H */
