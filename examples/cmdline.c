/*
  File autogenerated by gengetopt version 2.22.2
  generated with the following command:
  gengetopt 

  The developers of gengetopt consider the fixed text that goes in all
  gengetopt output files to be in the public domain:
  we make no copyright claims on it.
*/

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FIX_UNUSED
#define FIX_UNUSED(X) (void) (X) /* avoid warnings for unused params */
#endif

#include "getopt.h"

#include "cmdline.h"

const char *gengetopt_args_info_purpose = "";

const char *gengetopt_args_info_usage = "Usage: findlowweight [OPTIONS]...";

const char *gengetopt_args_info_description = "Find low weight words in a binary linear code.\n\nThe generating matrix is obtained from the standard input, only '0' and '1'\ncharacters are considered, others are ignored. The words found are printed on\nthe standard output.\nSee the documentation for further details.";

const char *gengetopt_args_info_help[] = {
  "  -h, --help           Print help and exit",
  "  -V, --version        Print version and exit",
  "\nBasics:",
  "  -n, --length=INT     length of the code",
  "  -k, --dimension=INT  dimension of the code",
  "  -w, --weight=INT     weight threshold",
  "  -s, --seed=INT       seed of the random number generator  (default=`24301')",
  "\nStop conditions:",
  "  Those options define when the program returns. The computation stops as soon \n  as one of the condition is satisfied.",
  "  -i, --max_iter=INT   maximum number of iteration  (default=`0')",
  "  -f, --max_found=INT  maximum number of different solutions  (default=`1')",
  "\nAdvanced:",
  "  Technical parameters, see the documentation for details.",
  "      --px=INT         size of the tuples for X  (default=`1')",
  "      --py=INT         size of the tuples for Y  (default=`1')",
  "      --kx=INT         number of rows in X  (default=`0')",
  "      --ky=INT         number of rows in Y  (default=`0')",
  "  -m, --m=INT          multiple widows before pivoting  (default=`1')",
  "  -l, --l=INT          length of the window  (default=`8')",
  "  -c, --c=INT          columns swapped for each pivot  (default=`1')",
  "  -r, --r=INT          size of the groups for pivoting  (default=`1')",
    0
};

typedef enum {ARG_NO
  , ARG_INT
} cmdline_parser_arg_type;

static
void clear_given (struct gengetopt_args_info *args_info);
static
void clear_args (struct gengetopt_args_info *args_info);

static int
cmdline_parser_internal (int argc, char * const *argv, struct gengetopt_args_info *args_info,
                        struct cmdline_parser_params *params, const char *additional_error);

static int
cmdline_parser_required2 (struct gengetopt_args_info *args_info, const char *prog_name, const char *additional_error);

static char *
gengetopt_strdup (const char *s);

static
void clear_given (struct gengetopt_args_info *args_info)
{
  args_info->help_given = 0 ;
  args_info->version_given = 0 ;
  args_info->length_given = 0 ;
  args_info->dimension_given = 0 ;
  args_info->weight_given = 0 ;
  args_info->seed_given = 0 ;
  args_info->max_iter_given = 0 ;
  args_info->max_found_given = 0 ;
  args_info->px_given = 0 ;
  args_info->py_given = 0 ;
  args_info->kx_given = 0 ;
  args_info->ky_given = 0 ;
  args_info->m_given = 0 ;
  args_info->l_given = 0 ;
  args_info->c_given = 0 ;
  args_info->r_given = 0 ;
}

static
void clear_args (struct gengetopt_args_info *args_info)
{
  FIX_UNUSED (args_info);
  args_info->length_orig = NULL;
  args_info->dimension_orig = NULL;
  args_info->weight_orig = NULL;
  args_info->seed_arg = 24301;
  args_info->seed_orig = NULL;
  args_info->max_iter_arg = 0;
  args_info->max_iter_orig = NULL;
  args_info->max_found_arg = 1;
  args_info->max_found_orig = NULL;
  args_info->px_arg = 1;
  args_info->px_orig = NULL;
  args_info->py_arg = 1;
  args_info->py_orig = NULL;
  args_info->kx_arg = 0;
  args_info->kx_orig = NULL;
  args_info->ky_arg = 0;
  args_info->ky_orig = NULL;
  args_info->m_arg = 1;
  args_info->m_orig = NULL;
  args_info->l_arg = 8;
  args_info->l_orig = NULL;
  args_info->c_arg = 1;
  args_info->c_orig = NULL;
  args_info->r_arg = 1;
  args_info->r_orig = NULL;
  
}

static
void init_args_info(struct gengetopt_args_info *args_info)
{


  args_info->help_help = gengetopt_args_info_help[0] ;
  args_info->version_help = gengetopt_args_info_help[1] ;
  args_info->length_help = gengetopt_args_info_help[3] ;
  args_info->dimension_help = gengetopt_args_info_help[4] ;
  args_info->weight_help = gengetopt_args_info_help[5] ;
  args_info->seed_help = gengetopt_args_info_help[6] ;
  args_info->max_iter_help = gengetopt_args_info_help[9] ;
  args_info->max_found_help = gengetopt_args_info_help[10] ;
  args_info->px_help = gengetopt_args_info_help[13] ;
  args_info->py_help = gengetopt_args_info_help[14] ;
  args_info->kx_help = gengetopt_args_info_help[15] ;
  args_info->ky_help = gengetopt_args_info_help[16] ;
  args_info->m_help = gengetopt_args_info_help[17] ;
  args_info->l_help = gengetopt_args_info_help[18] ;
  args_info->c_help = gengetopt_args_info_help[19] ;
  args_info->r_help = gengetopt_args_info_help[20] ;
  
}

void
cmdline_parser_print_version (void)
{
  printf ("%s %s\n",
     (strlen(CMDLINE_PARSER_PACKAGE_NAME) ? CMDLINE_PARSER_PACKAGE_NAME : CMDLINE_PARSER_PACKAGE),
     CMDLINE_PARSER_VERSION);
}

static void print_help_common(void) {
  cmdline_parser_print_version ();

  if (strlen(gengetopt_args_info_purpose) > 0)
    printf("\n%s\n", gengetopt_args_info_purpose);

  if (strlen(gengetopt_args_info_usage) > 0)
    printf("\n%s\n", gengetopt_args_info_usage);

  printf("\n");

  if (strlen(gengetopt_args_info_description) > 0)
    printf("%s\n\n", gengetopt_args_info_description);
}

void
cmdline_parser_print_help (void)
{
  int i = 0;
  print_help_common();
  while (gengetopt_args_info_help[i])
    printf("%s\n", gengetopt_args_info_help[i++]);
}

void
cmdline_parser_init (struct gengetopt_args_info *args_info)
{
  clear_given (args_info);
  clear_args (args_info);
  init_args_info (args_info);
}

void
cmdline_parser_params_init(struct cmdline_parser_params *params)
{
  if (params)
    { 
      params->override = 0;
      params->initialize = 1;
      params->check_required = 1;
      params->check_ambiguity = 0;
      params->print_errors = 1;
    }
}

struct cmdline_parser_params *
cmdline_parser_params_create(void)
{
  struct cmdline_parser_params *params = 
    (struct cmdline_parser_params *)malloc(sizeof(struct cmdline_parser_params));
  cmdline_parser_params_init(params);  
  return params;
}

static void
free_string_field (char **s)
{
  if (*s)
    {
      free (*s);
      *s = 0;
    }
}


static void
cmdline_parser_release (struct gengetopt_args_info *args_info)
{

  free_string_field (&(args_info->length_orig));
  free_string_field (&(args_info->dimension_orig));
  free_string_field (&(args_info->weight_orig));
  free_string_field (&(args_info->seed_orig));
  free_string_field (&(args_info->max_iter_orig));
  free_string_field (&(args_info->max_found_orig));
  free_string_field (&(args_info->px_orig));
  free_string_field (&(args_info->py_orig));
  free_string_field (&(args_info->kx_orig));
  free_string_field (&(args_info->ky_orig));
  free_string_field (&(args_info->m_orig));
  free_string_field (&(args_info->l_orig));
  free_string_field (&(args_info->c_orig));
  free_string_field (&(args_info->r_orig));
  
  

  clear_given (args_info);
}


static void
write_into_file(FILE *outfile, const char *opt, const char *arg, const char *values[])
{
  FIX_UNUSED (values);
  if (arg) {
    fprintf(outfile, "%s=\"%s\"\n", opt, arg);
  } else {
    fprintf(outfile, "%s\n", opt);
  }
}


int
cmdline_parser_dump(FILE *outfile, struct gengetopt_args_info *args_info)
{
  int i = 0;

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot dump options to stream\n", CMDLINE_PARSER_PACKAGE);
      return EXIT_FAILURE;
    }

  if (args_info->help_given)
    write_into_file(outfile, "help", 0, 0 );
  if (args_info->version_given)
    write_into_file(outfile, "version", 0, 0 );
  if (args_info->length_given)
    write_into_file(outfile, "length", args_info->length_orig, 0);
  if (args_info->dimension_given)
    write_into_file(outfile, "dimension", args_info->dimension_orig, 0);
  if (args_info->weight_given)
    write_into_file(outfile, "weight", args_info->weight_orig, 0);
  if (args_info->seed_given)
    write_into_file(outfile, "seed", args_info->seed_orig, 0);
  if (args_info->max_iter_given)
    write_into_file(outfile, "max_iter", args_info->max_iter_orig, 0);
  if (args_info->max_found_given)
    write_into_file(outfile, "max_found", args_info->max_found_orig, 0);
  if (args_info->px_given)
    write_into_file(outfile, "px", args_info->px_orig, 0);
  if (args_info->py_given)
    write_into_file(outfile, "py", args_info->py_orig, 0);
  if (args_info->kx_given)
    write_into_file(outfile, "kx", args_info->kx_orig, 0);
  if (args_info->ky_given)
    write_into_file(outfile, "ky", args_info->ky_orig, 0);
  if (args_info->m_given)
    write_into_file(outfile, "m", args_info->m_orig, 0);
  if (args_info->l_given)
    write_into_file(outfile, "l", args_info->l_orig, 0);
  if (args_info->c_given)
    write_into_file(outfile, "c", args_info->c_orig, 0);
  if (args_info->r_given)
    write_into_file(outfile, "r", args_info->r_orig, 0);
  

  i = EXIT_SUCCESS;
  return i;
}

int
cmdline_parser_file_save(const char *filename, struct gengetopt_args_info *args_info)
{
  FILE *outfile;
  int i = 0;

  outfile = fopen(filename, "w");

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot open file for writing: %s\n", CMDLINE_PARSER_PACKAGE, filename);
      return EXIT_FAILURE;
    }

  i = cmdline_parser_dump(outfile, args_info);
  fclose (outfile);

  return i;
}

void
cmdline_parser_free (struct gengetopt_args_info *args_info)
{
  cmdline_parser_release (args_info);
}

/** @brief replacement of strdup, which is not standard */
char *
gengetopt_strdup (const char *s)
{
  char *result = 0;
  if (!s)
    return result;

  result = (char*)malloc(strlen(s) + 1);
  if (result == (char*)0)
    return (char*)0;
  strcpy(result, s);
  return result;
}

int
cmdline_parser (int argc, char * const *argv, struct gengetopt_args_info *args_info)
{
  return cmdline_parser2 (argc, argv, args_info, 0, 1, 1);
}

int
cmdline_parser_ext (int argc, char * const *argv, struct gengetopt_args_info *args_info,
                   struct cmdline_parser_params *params)
{
  int result;
  result = cmdline_parser_internal (argc, argv, args_info, params, 0);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser2 (int argc, char * const *argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required)
{
  int result;
  struct cmdline_parser_params params;
  
  params.override = override;
  params.initialize = initialize;
  params.check_required = check_required;
  params.check_ambiguity = 0;
  params.print_errors = 1;

  result = cmdline_parser_internal (argc, argv, args_info, &params, 0);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser_required (struct gengetopt_args_info *args_info, const char *prog_name)
{
  int result = EXIT_SUCCESS;

  if (cmdline_parser_required2(args_info, prog_name, 0) > 0)
    result = EXIT_FAILURE;

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser_required2 (struct gengetopt_args_info *args_info, const char *prog_name, const char *additional_error)
{
  FIX_UNUSED (additional_error);
  int error = 0;

  /* checks for required options */
  if (! args_info->length_given)
    {
      fprintf (stderr, "%s: '--length' ('-n') option required%s\n", prog_name, (additional_error ? additional_error : ""));
      error = 1;
    }
  
  if (! args_info->dimension_given)
    {
      fprintf (stderr, "%s: '--dimension' ('-k') option required%s\n", prog_name, (additional_error ? additional_error : ""));
      error = 1;
    }
  
  if (! args_info->weight_given)
    {
      fprintf (stderr, "%s: '--weight' ('-w') option required%s\n", prog_name, (additional_error ? additional_error : ""));
      error = 1;
    }
  
  
  /* checks for dependences among options */

  return error;
}


static char *package_name = 0;

/**
 * @brief updates an option
 * @param field the generic pointer to the field to update
 * @param orig_field the pointer to the orig field
 * @param field_given the pointer to the number of occurrence of this option
 * @param prev_given the pointer to the number of occurrence already seen
 * @param value the argument for this option (if null no arg was specified)
 * @param possible_values the possible values for this option (if specified)
 * @param default_value the default value (in case the option only accepts fixed values)
 * @param arg_type the type of this option
 * @param check_ambiguity @see cmdline_parser_params.check_ambiguity
 * @param override @see cmdline_parser_params.override
 * @param no_free whether to free a possible previous value
 * @param multiple_option whether this is a multiple option
 * @param long_opt the corresponding long option
 * @param short_opt the corresponding short option (or '-' if none)
 * @param additional_error possible further error specification
 */
static
int update_arg(void *field, char **orig_field,
               unsigned int *field_given, unsigned int *prev_given, 
               char *value, const char *possible_values[],
               const char *default_value,
               cmdline_parser_arg_type arg_type,
               int check_ambiguity, int override,
               int no_free, int multiple_option,
               const char *long_opt, char short_opt,
               const char *additional_error)
{
  FIX_UNUSED (field);
  char *stop_char = 0;
  const char *val = value;
  int found;

  stop_char = 0;
  found = 0;

  if (!multiple_option && prev_given && (*prev_given || (check_ambiguity && *field_given)))
    {
      if (short_opt != '-')
        fprintf (stderr, "%s: `--%s' (`-%c') option given more than once%s\n", 
               package_name, long_opt, short_opt,
               (additional_error ? additional_error : ""));
      else
        fprintf (stderr, "%s: `--%s' option given more than once%s\n", 
               package_name, long_opt,
               (additional_error ? additional_error : ""));
      return 1; /* failure */
    }

  FIX_UNUSED (default_value);
    
  if (field_given && *field_given && ! override)
    return 0;
  if (prev_given)
    (*prev_given)++;
  if (field_given)
    (*field_given)++;
  if (possible_values)
    val = possible_values[found];

  switch(arg_type) {
  case ARG_INT:
    if (val) *((int *)field) = strtol (val, &stop_char, 0);
    break;
  default:
    break;
  };

  /* check numeric conversion */
  switch(arg_type) {
  case ARG_INT:
    if (val && !(stop_char && *stop_char == '\0')) {
      fprintf(stderr, "%s: invalid numeric value: %s\n", package_name, val);
      return 1; /* failure */
    }
    break;
  default:
    ;
  };

  /* store the original value */
  switch(arg_type) {
  case ARG_NO:
    break;
  default:
    if (value && orig_field) {
      if (no_free) {
        *orig_field = value;
      } else {
        if (*orig_field)
          free (*orig_field); /* free previous string */
        *orig_field = gengetopt_strdup (value);
      }
    }
  };

  return 0; /* OK */
}


int
cmdline_parser_internal (
  int argc, char * const *argv, struct gengetopt_args_info *args_info,
                        struct cmdline_parser_params *params, const char *additional_error)
{
  int c;	/* Character of the parsed option.  */

  int error = 0;
  struct gengetopt_args_info local_args_info;
  
  int override;
  int initialize;
  int check_required;
  int check_ambiguity;
  
  package_name = argv[0];
  
  override = params->override;
  initialize = params->initialize;
  check_required = params->check_required;
  check_ambiguity = params->check_ambiguity;

  if (initialize)
    cmdline_parser_init (args_info);

  cmdline_parser_init (&local_args_info);

  optarg = 0;
  optind = 0;
  opterr = params->print_errors;
  optopt = '?';

  while (1)
    {
      int option_index = 0;

      static struct option long_options[] = {
        { "help",	0, NULL, 'h' },
        { "version",	0, NULL, 'V' },
        { "length",	1, NULL, 'n' },
        { "dimension",	1, NULL, 'k' },
        { "weight",	1, NULL, 'w' },
        { "seed",	1, NULL, 's' },
        { "max_iter",	1, NULL, 'i' },
        { "max_found",	1, NULL, 'f' },
        { "px",	1, NULL, 0 },
        { "py",	1, NULL, 0 },
        { "kx",	1, NULL, 0 },
        { "ky",	1, NULL, 0 },
        { "m",	1, NULL, 'm' },
        { "l",	1, NULL, 'l' },
        { "c",	1, NULL, 'c' },
        { "r",	1, NULL, 'r' },
        { 0,  0, 0, 0 }
      };

      c = getopt_long (argc, argv, "hVn:k:w:s:i:f:m:l:c:r:", long_options, &option_index);

      if (c == -1) break;	/* Exit from `while (1)' loop.  */

      switch (c)
        {
        case 'h':	/* Print help and exit.  */
          cmdline_parser_print_help ();
          cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'V':	/* Print version and exit.  */
          cmdline_parser_print_version ();
          cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'n':	/* length of the code.  */
        
        
          if (update_arg( (void *)&(args_info->length_arg), 
               &(args_info->length_orig), &(args_info->length_given),
              &(local_args_info.length_given), optarg, 0, 0, ARG_INT,
              check_ambiguity, override, 0, 0,
              "length", 'n',
              additional_error))
            goto failure;
        
          break;
        case 'k':	/* dimension of the code.  */
        
        
          if (update_arg( (void *)&(args_info->dimension_arg), 
               &(args_info->dimension_orig), &(args_info->dimension_given),
              &(local_args_info.dimension_given), optarg, 0, 0, ARG_INT,
              check_ambiguity, override, 0, 0,
              "dimension", 'k',
              additional_error))
            goto failure;
        
          break;
        case 'w':	/* weight threshold.  */
        
        
          if (update_arg( (void *)&(args_info->weight_arg), 
               &(args_info->weight_orig), &(args_info->weight_given),
              &(local_args_info.weight_given), optarg, 0, 0, ARG_INT,
              check_ambiguity, override, 0, 0,
              "weight", 'w',
              additional_error))
            goto failure;
        
          break;
        case 's':	/* seed of the random number generator.  */
        
        
          if (update_arg( (void *)&(args_info->seed_arg), 
               &(args_info->seed_orig), &(args_info->seed_given),
              &(local_args_info.seed_given), optarg, 0, "24301", ARG_INT,
              check_ambiguity, override, 0, 0,
              "seed", 's',
              additional_error))
            goto failure;
        
          break;
        case 'i':	/* maximum number of iteration.  */
        
        
          if (update_arg( (void *)&(args_info->max_iter_arg), 
               &(args_info->max_iter_orig), &(args_info->max_iter_given),
              &(local_args_info.max_iter_given), optarg, 0, "0", ARG_INT,
              check_ambiguity, override, 0, 0,
              "max_iter", 'i',
              additional_error))
            goto failure;
        
          break;
        case 'f':	/* maximum number of different solutions.  */
        
        
          if (update_arg( (void *)&(args_info->max_found_arg), 
               &(args_info->max_found_orig), &(args_info->max_found_given),
              &(local_args_info.max_found_given), optarg, 0, "1", ARG_INT,
              check_ambiguity, override, 0, 0,
              "max_found", 'f',
              additional_error))
            goto failure;
        
          break;
        case 'm':	/* multiple widows before pivoting.  */
        
        
          if (update_arg( (void *)&(args_info->m_arg), 
               &(args_info->m_orig), &(args_info->m_given),
              &(local_args_info.m_given), optarg, 0, "1", ARG_INT,
              check_ambiguity, override, 0, 0,
              "m", 'm',
              additional_error))
            goto failure;
        
          break;
        case 'l':	/* length of the window.  */
        
        
          if (update_arg( (void *)&(args_info->l_arg), 
               &(args_info->l_orig), &(args_info->l_given),
              &(local_args_info.l_given), optarg, 0, "8", ARG_INT,
              check_ambiguity, override, 0, 0,
              "l", 'l',
              additional_error))
            goto failure;
        
          break;
        case 'c':	/* columns swapped for each pivot.  */
        
        
          if (update_arg( (void *)&(args_info->c_arg), 
               &(args_info->c_orig), &(args_info->c_given),
              &(local_args_info.c_given), optarg, 0, "1", ARG_INT,
              check_ambiguity, override, 0, 0,
              "c", 'c',
              additional_error))
            goto failure;
        
          break;
        case 'r':	/* size of the groups for pivoting.  */
        
        
          if (update_arg( (void *)&(args_info->r_arg), 
               &(args_info->r_orig), &(args_info->r_given),
              &(local_args_info.r_given), optarg, 0, "1", ARG_INT,
              check_ambiguity, override, 0, 0,
              "r", 'r',
              additional_error))
            goto failure;
        
          break;

        case 0:	/* Long option with no short option */
          /* size of the tuples for X.  */
          if (strcmp (long_options[option_index].name, "px") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->px_arg), 
                 &(args_info->px_orig), &(args_info->px_given),
                &(local_args_info.px_given), optarg, 0, "1", ARG_INT,
                check_ambiguity, override, 0, 0,
                "px", '-',
                additional_error))
              goto failure;
          
          }
          /* size of the tuples for Y.  */
          else if (strcmp (long_options[option_index].name, "py") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->py_arg), 
                 &(args_info->py_orig), &(args_info->py_given),
                &(local_args_info.py_given), optarg, 0, "1", ARG_INT,
                check_ambiguity, override, 0, 0,
                "py", '-',
                additional_error))
              goto failure;
          
          }
          /* number of rows in X.  */
          else if (strcmp (long_options[option_index].name, "kx") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->kx_arg), 
                 &(args_info->kx_orig), &(args_info->kx_given),
                &(local_args_info.kx_given), optarg, 0, "0", ARG_INT,
                check_ambiguity, override, 0, 0,
                "kx", '-',
                additional_error))
              goto failure;
          
          }
          /* number of rows in Y.  */
          else if (strcmp (long_options[option_index].name, "ky") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->ky_arg), 
                 &(args_info->ky_orig), &(args_info->ky_given),
                &(local_args_info.ky_given), optarg, 0, "0", ARG_INT,
                check_ambiguity, override, 0, 0,
                "ky", '-',
                additional_error))
              goto failure;
          
          }
          
          break;
        case '?':	/* Invalid option.  */
          /* `getopt_long' already printed an error message.  */
          goto failure;

        default:	/* bug: option not considered.  */
          fprintf (stderr, "%s: option unknown: %c%s\n", CMDLINE_PARSER_PACKAGE, c, (additional_error ? additional_error : ""));
          abort ();
        } /* switch */
    } /* while */



  if (check_required)
    {
      error += cmdline_parser_required2 (args_info, argv[0], additional_error);
    }

  cmdline_parser_release (&local_args_info);

  if ( error )
    return (EXIT_FAILURE);

  return 0;

failure:
  
  cmdline_parser_release (&local_args_info);
  return (EXIT_FAILURE);
}