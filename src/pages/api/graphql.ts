import { ApolloServer, gql } from 'apollo-server-micro';

type Contact = {
  id: string;
  firstName: string;
  lastName: string;
  mobile: string;
  email: string;
  address: string;
};

type VendorFollowUp = {
  id: string;
  title: string;
  subtitle: string;
  imageUrl: string;
  agent: Agent;
  contact: Contact;
};

type Agent = {
  id: string;
  name: string;
  jobTitle: string;
  description: string;
  profileImageUrl: string;
  email: string;
  mobile: string;
  brandingColor: string;
  logoUrl: string;
};

const typeDefs = gql`
  type Query {
    vendorFollowUp(token: ID!): VendorFollowUp
  }

  type Contact {
    id: ID!
    firstName: String!
    lastName: String!
    mobile: String!
    email: String!
    address: String!
  }

  type VendorFollowUp {
    id: ID!
    title: String!
    subtitle: String!
    imageUrl: String!
    agent: Agent!
    contact: Contact!
  }

  type Agent {
    id: ID!
    name: String!
    jobTitle: String!
    description: String!
    profileImageUrl: String!
    email: String!
    mobile: String!
    brandingColor: String!
    logoUrl: String!
  }
`;

const getVendorFollowUpsByToken: ({ token: string }) => VendorFollowUp = ({
  token,
}) => {
  const contact: Contact = {
    id: `Contact:${token}`,
    firstName: 'John',
    lastName: 'Woo',
    mobile: '0405867463',
    email: 'stink@poo.com',
    address: '39 Street, 3126 Wooloongong, Victoria',
  };

  const agent: Agent = {
    id: `Agent:${token}`,
    name: 'A Name',
    jobTitle: 'Chief guru',
    description: 'Super motivated',
    profileImageUrl:
      'https://pickaface.net/gallery/avatar/unr_fakeeliot_181127_1929_w34iu.png',
    email: 'blah@test.com',
    mobile: '045679777',
    brandingColor: 'yellow',
    logoUrl:
      'https://www.raywhite.com/wp-content/resources/uiframework/img/rw-logo-2017.svg',
  };

  const vendorFollowUp: VendorFollowUp = {
    id: `VendorFollowUp:${token}`,
    title: 'a title',
    subtitle: 'a subtitle',
    imageUrl:
      'https://pickaface.net/gallery/avatar/unr_fakeeliot_181127_1929_w34iu.png',
    contact,
    agent,
  };

  return vendorFollowUp;
};

export const queryResolvers = {
  vendorFollowUp: async (_: any, { token }) =>
    getVendorFollowUpsByToken({ token }),
};

const resolvers: any = {
  Query: {
    ...queryResolvers,
  },
};

const server = new ApolloServer({
  typeDefs,
  resolvers,
  introspection: true,
  playground: true,
});

export const config = {
  api: {
    bodyParser: false,
  },
};

export default server.createHandler({ path: '/api/graphql' });
