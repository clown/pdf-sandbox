/* ------------------------------------------------------------------------- */
/*
 *  contents/round_rect.h
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
#ifndef FAML_PDF_CONTENTS_FOLDED_CORNER_H
#define FAML_PDF_CONTENTS_FOLDED_CORNER_H

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
			//  basic_folded_corner
			/* ------------------------------------------------------------- */
			template <
				class CharT,
				class Traits = std::char_traits<CharT>
			>
			class basic_folded_corner : public basic_polygon<CharT, Traits> {
			public:
				typedef basic_polygon<CharT, Traits> super;
				typedef typename super::size_type size_type;
				typedef typename super::ostream_type ostream_type;
				
				explicit basic_folded_corner(const coordinate& o, double w, double h, bool entag = true) :
					super(o, w, h), entag_(entag), adjust_(0.16667) {}
				
				virtual ~basic_folded_corner() throw() {}
				
				virtual bool operator()(ostream_type& out) {
					// No need to draw and/or fill the shape.
					if (!this->is_stroke() && !this->is_fill()) return true;
					
					if (entag_) out << LITERAL("q") << std::endl;
					
					this->setorigin(out);
					this->setborder(out);
					this->setbackground(out);
					
					double ox = -this->width() / 2.0;
					double oy = -this->height() / 2.0;
					double delta = (this->width() < this->height()) ? this->width() * adjust_ : this->height() * adjust_;
					
					// Phase 1
					out << fmt(LITERAL("%f %f m")) % (ox) % (oy) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox) % (oy + this->height()) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox + this->width()) % (oy + this->height()) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox + this->width()) % (oy + delta) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox + this->width() - delta) % (oy) << std::endl;
					if (this->is_stroke() && this->is_fill()) out << LITERAL("b") << std::endl;
					else if (this->is_fill()) out << LITERAL("f") << std::endl;
					else out << LITERAL("s") << std::endl;
					
					// Phase 2
					double red = this->background().red() * this->shadow().red();
					double green = this->background().green() * this->shadow().green();
					double blue = this->background().blue() * this->shadow().blue();
					out << fmt(LITERAL("%f %f %f rg")) % red % green % blue << std::endl;
					out << fmt(LITERAL("%f %f m")) % (ox + this->width() - delta) % (oy) << std::endl;
					out << fmt(LITERAL("%f %f l")) % (ox + this->width()) % (oy + delta) << std::endl;
					double fold_rate = 0.8;
					out << fmt(LITERAL("%f %f l")) % (ox + this->width() - delta*fold_rate) % (oy + delta*fold_rate) << std::endl;
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
			typedef basic_folded_corner<char> folded_corner;
		}
	}
}

#endif // FAML_PDF_CONTENTS_FOLDED_CORNER_H
