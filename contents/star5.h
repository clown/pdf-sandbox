/* ------------------------------------------------------------------------- */
/*
 *  contents/star5.h
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
#ifndef FAML_PDF_CONTENTS_STAR5_H
#define FAML_PDF_CONTENTS_STAR5_H

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
			//  basic_star5
			/* ------------------------------------------------------------- */
			template <
				class CharT,
				class Traits = std::char_traits<CharT>
			>
			class basic_star5 : public basic_polygon<CharT, Traits> {
			public:
				typedef basic_polygon<CharT, Traits> super;
				typedef typename super::size_type size_type;
				typedef typename super::ostream_type ostream_type;
				
				explicit basic_star5(const coordinate& o, double w, double h, bool entag = true) :
					super(o, w, h), entag_(entag), adjust_(0.18889) {}
				
				virtual ~basic_star5() throw() {}
				
				virtual bool operator()(ostream_type& out) {
					// No need to draw and/or fill the shape.
					if (!this->is_stroke() && !this->is_fill()) return true;
					
					double ox = 0;
					double oy = 0;
					
					const double PI = 3.1415;
					double rad = 360 * PI /  (5 * 180.0);
					
					// 21600 * 21600
					double ox1 = 0;
					double oy1 = 10800;
					double ox2 = ox1 * cos(rad) - oy1 * sin(rad);
					double oy2 = ox1 * sin(rad) + oy1 * cos(rad);
					double ox3 = ox2 * cos(rad) - oy2 * sin(rad);
					double oy3 = ox2 * sin(rad) + oy2 * cos(rad);
					double ox5 = ox1 * cos(-rad) - oy1 * sin(-rad);
					double oy5 = ox1 * sin(-rad) + oy1 * cos(-rad);
					double ox4 = ox5 * cos(-rad) - oy5 * sin(-rad);
					double oy4 = ox5 * sin(-rad) + oy5 * cos(-rad);
					
					// 21600 * 21600
					double ix1 = - 21600 * adjust_ * sin(rad/2.0);
					double iy1 = 21600 * adjust_ * cos(rad/2.0);
					double ix2 = ix1 * cos(rad) - iy1 * sin(rad);
					double iy2 = ix1 * sin(rad) + iy1 * cos(rad);
					double ix3 = ix2 * cos(rad) - iy2 * sin(rad);
					double iy3 = ix2 * sin(rad) + iy2 * cos(rad);
					double ix5 = ix1 * cos(-rad) - iy1 * sin(-rad);
					double iy5 = ix1 * sin(-rad) + iy1 * cos(-rad);
					double ix4 = ix5 * cos(-rad) - iy5 * sin(-rad);
					double iy4 = ix5 * sin(-rad) + iy5 * cos(-rad);
					
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
			typedef basic_star5<char> star5;
		}
	}
}

#endif // FAML_PDF_CONTENTS_STAR5_H
