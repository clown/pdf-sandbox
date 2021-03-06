/* ------------------------------------------------------------------------- */
/*
 *  contents/star24.h
 *
 *  Copyright (c) 2009, Four and More, Inc. All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    - Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    - Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    - No names of its contributors may be used to endorse or promote
 *      products derived from this software without specific prior written
 *      permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 *  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 *  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  Last-modified: Fri 05 Jun 2009 00:09:00 JST
 */
/* ------------------------------------------------------------------------- */
#ifndef FAML_PDF_CONTENTS_STAR24_H
#define FAML_PDF_CONTENTS_STAR24_H

#ifndef FAML_PDF_CONTENTS_SHAPE_H
#include "shape.h"
#endif // FAML_PDF_CONTENTS_SHAPE_H

#include <cassert>
#include <vector>
#include "clx/format.h"
#include "clx/literal.h"
#include "circle.h"
#include "../unit.h"

namespace faml {
	namespace pdf {
		namespace contents {
			/* ------------------------------------------------------------- */
			//  basic_star24
			/* ------------------------------------------------------------- */
			template <
				class CharT,
				class Traits = std::char_traits<CharT>
			>
			class basic_star24 : public basic_polygon<CharT, Traits> {
			public:
				typedef basic_polygon<CharT, Traits> super;
				typedef typename super::size_type size_type;
				typedef typename super::ostream_type ostream_type;
				
				explicit basic_star24(const coordinate& o, double w, double h, bool entag = true) :
					super(o, w, h), entag_(entag), adjust_(0.375) {}
				
				virtual ~basic_star24() throw() {}
				
				virtual bool operator()(ostream_type& out) {
					// No need to draw and/or fill the shape.
					if (!this->is_stroke() && !this->is_fill()) return true;
					
					double ox = 0;
					double oy = 0;
					if(adjust_ > 0.5) adjust_ = 0.5;
					
					const double PI = 3.1415;
					double rad = 360 * PI /  (24 * 180.0);
					
					// 21600 * 21600
					double ox1 = 0;
					double oy1 = 10800;
					double ox2 = ox1 * cos(rad) - oy1 * sin(rad);
					double oy2 = ox1 * sin(rad) + oy1 * cos(rad);
					double ox3 = ox2 * cos(rad) - oy2 * sin(rad);
					double oy3 = ox2 * sin(rad) + oy2 * cos(rad);
					double ox4 = ox3 * cos(rad) - oy3 * sin(rad);
					double oy4 = ox3 * sin(rad) + oy3 * cos(rad);
					double ox5 = ox4 * cos(rad) - oy4 * sin(rad);
					double oy5 = ox4 * sin(rad) + oy4 * cos(rad);
					double ox6 = ox5 * cos(rad) - oy5 * sin(rad);
					double oy6 = ox5 * sin(rad) + oy5 * cos(rad);
					double ox7 = ox6 * cos(rad) - oy6 * sin(rad);
					double oy7 = ox6 * sin(rad) + oy6 * cos(rad);
					double ox8 = ox7 * cos(rad) - oy7 * sin(rad);
					double oy8 = ox7 * sin(rad) + oy7 * cos(rad);
					double ox9 = ox8 * cos(rad) - oy8 * sin(rad);
					double oy9 = ox8 * sin(rad) + oy8 * cos(rad);
					double ox10 = ox9 * cos(rad) - oy9 * sin(rad);
					double oy10 = ox9 * sin(rad) + oy9 * cos(rad);
					double ox11 = ox10 * cos(rad) - oy10 * sin(rad);
					double oy11 = ox10 * sin(rad) + oy10 * cos(rad);
					double ox12 = ox11 * cos(rad) - oy11 * sin(rad);
					double oy12 = ox11 * sin(rad) + oy11 * cos(rad);
					double ox13 = ox12 * cos(rad) - oy12 * sin(rad);
					double oy13 = ox12 * sin(rad) + oy12 * cos(rad);
					double ox24 = ox1 * cos(-rad) - oy1 * sin(-rad);
					double oy24 = ox1 * sin(-rad) + oy1 * cos(-rad);
					double ox23 = ox24 * cos(-rad) - oy24 * sin(-rad);
					double oy23 = ox24 * sin(-rad) + oy24 * cos(-rad);
					double ox22 = ox23 * cos(-rad) - oy23 * sin(-rad);
					double oy22 = ox23 * sin(-rad) + oy23 * cos(-rad);
					double ox21 = ox22 * cos(-rad) - oy22 * sin(-rad);
					double oy21 = ox22 * sin(-rad) + oy22 * cos(-rad);
					double ox20 = ox21 * cos(-rad) - oy21 * sin(-rad);
					double oy20 = ox21 * sin(-rad) + oy21 * cos(-rad);
					double ox19 = ox20 * cos(-rad) - oy20 * sin(-rad);
					double oy19 = ox20 * sin(-rad) + oy20 * cos(-rad);
					double ox18 = ox19 * cos(-rad) - oy19 * sin(-rad);
					double oy18 = ox19 * sin(-rad) + oy19 * cos(-rad);
					double ox17 = ox18 * cos(-rad) - oy18 * sin(-rad);
					double oy17 = ox18 * sin(-rad) + oy18 * cos(-rad);
					double ox16 = ox17 * cos(-rad) - oy17 * sin(-rad);
					double oy16 = ox17 * sin(-rad) + oy17 * cos(-rad);
					double ox15 = ox16 * cos(-rad) - oy16 * sin(-rad);
					double oy15 = ox16 * sin(-rad) + oy16 * cos(-rad);
					double ox14 = ox15 * cos(-rad) - oy15 * sin(-rad);
					double oy14 = ox15 * sin(-rad) + oy15 * cos(-rad);
					
					// 21600 * 21600
					double ix1 = - 21600 * adjust_ * sin(rad/2.0);
					double iy1 = 21600 * adjust_ * cos(rad/2.0);
					double ix2 = ix1 * cos(rad) - iy1 * sin(rad);
					double iy2 = ix1 * sin(rad) + iy1 * cos(rad);
					double ix3 = ix2 * cos(rad) - iy2 * sin(rad);
					double iy3 = ix2 * sin(rad) + iy2 * cos(rad);
					double ix4 = ix3 * cos(rad) - iy3 * sin(rad);
					double iy4 = ix3 * sin(rad) + iy3 * cos(rad);
					double ix5 = ix4 * cos(rad) - iy4 * sin(rad);
					double iy5 = ix4 * sin(rad) + iy4 * cos(rad);
					double ix6 = ix5 * cos(rad) - iy5 * sin(rad);
					double iy6 = ix5 * sin(rad) + iy5 * cos(rad);
					double ix7 = ix6 * cos(rad) - iy6 * sin(rad);
					double iy7 = ix6 * sin(rad) + iy6 * cos(rad);
					double ix8 = ix7 * cos(rad) - iy7 * sin(rad);
					double iy8 = ix7 * sin(rad) + iy7 * cos(rad);
					double ix9 = ix8 * cos(rad) - iy8 * sin(rad);
					double iy9 = ix8 * sin(rad) + iy8 * cos(rad);
					double ix10 = ix9 * cos(rad) - iy9 * sin(rad);
					double iy10 = ix9 * sin(rad) + iy9 * cos(rad);
					double ix11 = ix10 * cos(rad) - iy10 * sin(rad);
					double iy11 = ix10 * sin(rad) + iy10 * cos(rad);
					double ix12 = ix11 * cos(rad) - iy11 * sin(rad);
					double iy12 = ix11 * sin(rad) + iy11 * cos(rad);
					double ix13 = ix12 * cos(rad) - iy12 * sin(rad);
					double iy13 = ix12 * sin(rad) + iy12 * cos(rad);
					double ix24 = ix1 * cos(-rad) - iy1 * sin(-rad);
					double iy24 = ix1 * sin(-rad) + iy1 * cos(-rad);
					double ix23 = ix24 * cos(-rad) - iy24 * sin(-rad);
					double iy23 = ix24 * sin(-rad) + iy24 * cos(-rad);
					double ix22 = ix23 * cos(-rad) - iy23 * sin(-rad);
					double iy22 = ix23 * sin(-rad) + iy23 * cos(-rad);
					double ix21 = ix22 * cos(-rad) - iy22 * sin(-rad);
					double iy21 = ix22 * sin(-rad) + iy22 * cos(-rad);
					double ix20 = ix21 * cos(-rad) - iy21 * sin(-rad);
					double iy20 = ix21 * sin(-rad) + iy21 * cos(-rad);
					double ix19 = ix20 * cos(-rad) - iy20 * sin(-rad);
					double iy19 = ix20 * sin(-rad) + iy20 * cos(-rad);
					double ix18 = ix19 * cos(-rad) - iy19 * sin(-rad);
					double iy18 = ix19 * sin(-rad) + iy19 * cos(-rad);
					double ix17 = ix18 * cos(-rad) - iy18 * sin(-rad);
					double iy17 = ix18 * sin(-rad) + iy18 * cos(-rad);
					double ix16 = ix17 * cos(-rad) - iy17 * sin(-rad);
					double iy16 = ix17 * sin(-rad) + iy17 * cos(-rad);
					double ix15 = ix16 * cos(-rad) - iy16 * sin(-rad);
					double iy15 = ix16 * sin(-rad) + iy16 * cos(-rad);
					double ix14 = ix15 * cos(-rad) - iy15 * sin(-rad);
					double iy14 = ix15 * sin(-rad) + iy15 * cos(-rad);
					
					if (entag_) out << LITERAL("q") << std::endl;
					this->setorigin(out);
					this->setborder(out);
					this->setbackground(out);
					out << fmt(LITERAL("%f %f m")) % (ox+ox1*this->width()/21600.0) % (oy+oy1*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix1*this->width()/21600.0) % (oy+iy1*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ox2*this->width()/21600.0) % (oy+oy2*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix2*this->width()/21600.0) % (oy+iy2*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ox3*this->width()/21600.0) % (oy+oy3*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix3*this->width()/21600.0) % (oy+iy3*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ox4*this->width()/21600.0) % (oy+oy4*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix4*this->width()/21600.0) % (oy+iy4*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ox5*this->width()/21600.0) % (oy+oy5*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix5*this->width()/21600.0) % (oy+iy5*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ox6*this->width()/21600.0) % (oy+oy6*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix6*this->width()/21600.0) % (oy+iy6*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ox7*this->width()/21600.0) % (oy+oy7*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix7*this->width()/21600.0) % (oy+iy7*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ox8*this->width()/21600.0) % (oy+oy8*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix8*this->width()/21600.0) % (oy+iy8*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ox9*this->width()/21600.0) % (oy+oy9*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix9*this->width()/21600.0) % (oy+iy9*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ox10*this->width()/21600.0) % (oy+oy10*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix10*this->width()/21600.0) % (oy+iy10*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ox11*this->width()/21600.0) % (oy+oy11*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix11*this->width()/21600.0) % (oy+iy11*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ox12*this->width()/21600.0) % (oy+oy12*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix12*this->width()/21600.0) % (oy+iy12*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ox13*this->width()/21600.0) % (oy+oy13*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix13*this->width()/21600.0) % (oy+iy13*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ox14*this->width()/21600.0) % (oy+oy14*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix14*this->width()/21600.0) % (oy+iy14*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ox15*this->width()/21600.0) % (oy+oy15*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix15*this->width()/21600.0) % (oy+iy15*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ox16*this->width()/21600.0) % (oy+oy16*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix16*this->width()/21600.0) % (oy+iy16*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ox17*this->width()/21600.0) % (oy+oy17*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix17*this->width()/21600.0) % (oy+iy17*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ox18*this->width()/21600.0) % (oy+oy18*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix18*this->width()/21600.0) % (oy+iy18*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ox19*this->width()/21600.0) % (oy+oy19*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix19*this->width()/21600.0) % (oy+iy19*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ox20*this->width()/21600.0) % (oy+oy20*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix20*this->width()/21600.0) % (oy+iy20*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ox21*this->width()/21600.0) % (oy+oy21*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix21*this->width()/21600.0) % (oy+iy21*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ox22*this->width()/21600.0) % (oy+oy22*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix22*this->width()/21600.0) % (oy+iy22*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ox23*this->width()/21600.0) % (oy+oy23*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix23*this->width()/21600.0) % (oy+iy23*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ox24*this->width()/21600.0) % (oy+oy24*this->height()/21600.0) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox+ix24*this->width()/21600.0) % (oy+iy24*this->height()/21600.0) << std::endl;
					if (this->is_stroke() && this->is_fill()) out << LITERAL("b") << std::endl;
					else if (this->is_fill()) out << LITERAL("f") << std::endl;
					else out << LITERAL("s") << std::endl;
					if (entag_) out << LITERAL("Q") << std::endl;
					
					return true;
				}
				
				virtual size_type has_adjust() const { return 1; }
				virtual double adjust(size_type pos = 0) const { return adjust_; }
				virtual void adjust(double value, size_type pos = 0) { adjust_ = value; }
				
			private:
				typedef clx::basic_format<CharT, Traits> fmt;
				
				bool entag_;
				double adjust_;
			};
			typedef basic_star24<char> star24;
		}
	}
}

#endif // FAML_PDF_CONTENTS_STAR24_H
