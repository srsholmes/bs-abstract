open Interface;

module Additive = {
  module Semigroup: SEMIGROUP with type t = float = {
    type t = float;
    let append = (+.);
  };
  module Monoid: MONOID with type t = float = {
    include Semigroup;
    let empty = 0.0;
  };
};

module Multiplicative = {
  module Semigroup: SEMIGROUP with type t = float = {
    type t = float;
    let append = (*.);
  };
  module Monoid: MONOID with type t = float = {
    include Semigroup;
    let empty = 1.0;
  };
};

module Eq: EQ with type t = float = {
  type t = float;
  let eq = (==);
};

module Ord: ORD with type t = float = {
  include Eq;
  let compare = unsafe_compare;
};