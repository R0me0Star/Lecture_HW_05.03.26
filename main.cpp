template < class T > struct Billist
{
  T val;
  BilList< T > *next;
  BilList< T > *prev;
};

template < class T > class CircularBiList
{
private:
  BiList< T > *fake;
  size_t list_size;

public:
  CircularBiList();
  ~CircularBiList();

  CircularBiList(const CircularBiList &) = delete;
  CircularBiList &operator=(const CircularBiList &) = delete;

  void push_back(const T &value);
  void pop_back();
  bool is_empty() const noexcept;
  size_t size() const noexcept;
};

template < class T > CircularBiList< T >::CircularBiList()
{
  fake = new BiList< T >();
  fake->next = fake;
  fake->prev = fake;
  list_size = 0;
}
