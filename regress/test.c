// Test HTML escaping.
// @since Sun Aug  3 20:16:34 EDT 2014
// @author Mark Bucciarelli <mkbucc@gmail.com>


#include "tap.h"

#include "../htmlescape.h"

void
amp()
{
	char		*result = 0;
		
	htmlescape("&", &result);
	is(result, "&amp;");
	free(result);
}

void
lt()
{
	char		*result = 0;
		
	htmlescape("<", &result);
	is(result, "&lt;");
	free(result);
}

void
gt()
{
	char		*result = 0;
		
	htmlescape(">", &result);
	is(result, "&gt;");
	free(result);
}

void
quote()
{
	char		*result = 0;
		
	htmlescape("\\\"", &result);
	is(result, "&quot;");
	free(result);
}

void
amp_lt_gt_quote()
{
	char		*result = 0;
		
	htmlescape("& < > \\\"", &result);
	is(result, "&amp; &lt; &gt; &quot;");
	free(result);
}

void
gt_quote_amp_lt_nospace()
{
	char		*result = 0;
		
	htmlescape(">\\\"&<", &result);
	is(result, "&gt;&quot;&amp;&lt;");
	free(result);
}


void
handle_null_src()
{
	char		*result = 0;

	lives_ok( { htmlescape(0, result); }, "passing null src string should work." );
}

void
handle_null_dst()
{
	lives_ok( { htmlescape("", 0); }, "passing null dst pointer should work." );
}


void
handle_null_both()
{
	lives_ok( { htmlescape(0, 0); }, "both args null should work" );
}




int
main (int argc, char *argv[])
{

	plan(6);

	amp();
	lt();
	gt();
	quote();
	amp_lt_gt_quote();
	gt_quote_amp_lt_nospace();

	handle_null_src();
	handle_null_dst();
	handle_null_both();


	done_testing();
}
